// Kevin Tran
// COP4600
// Programming Assignment 1

package main

import (
    "bufio"
    "fmt"
    "log"
    "os"
    "regexp"
    "strconv"
    "strings"
)

func after(value string, a string) string {
    pos := strings.LastIndex(value, a)
    if pos == -1 {
        return ""
    }
    adjustedPos := pos + len(a)
    if adjustedPos >= len(value) {
        return ""
    }
    return value[adjustedPos:len(value)]
}

func between(value string, a string, b string) string {
    // Get substring between two strings.
    posFirst := strings.Index(value, a)
    if posFirst == -1 {
        return ""
    }
    posLast := strings.Index(value, b)
    if posLast == -1 {
        return ""
    }
    posFirstAdjusted := posFirst + len(a)
    if posFirstAdjusted >= posLast {
        return ""
    }
    return value[posFirstAdjusted:posLast]
}

func checkAtoi(e error) {
    if e != nil {
        log.Fatal(e)
    }
}

func checkFile(e error) {
    if e != nil {
        log.Fatal(e)
    }
}

func main() {
    // Get command line arguments
    inputArg := os.Args[1]
    outputArg := os.Args[2]
    
    // Verify input file
    inputFile, errFile := os.Open(inputArg)
    checkFile(errFile)
    defer inputFile.Close()

    // Read the input file
    var lines [16] string
    var lineNumber int = 0
    scanner := bufio.NewScanner(inputFile)
    scanner.Split(bufio.ScanLines)
    for scanner.Scan() {
        lines[lineNumber] = scanner.Text()
        lineNumber++
    }
    if e := scanner.Err(); e != nil {
        log.Fatal(e)
    }

    // Parse the input file
    var processCount, runFor, algorithm, quantum int
    var processes [10] string
    var processIndex int = 0
    var useString string
    var errAtoi error
    reInt := regexp.MustCompile("[0-9]+")
    reUseString := regexp.MustCompile("((fcfs)|(sjf)|(rr))+")
    for _, element := range lines {
        if strings.Contains(element, "processcount") {
            processCount, errAtoi = strconv.Atoi(reInt.FindString(element))
            checkAtoi(errAtoi)
        } else if strings.Contains(element, "runfor") {
            runFor, errAtoi = strconv.Atoi(reInt.FindString(element))
            checkAtoi(errAtoi)
        } else if strings.Contains(element, "use") {
            useString = reUseString.FindString(element)
            if strings.Compare(useString, "fcfs") == 0 {
                algorithm = 1
            } else if strings.Compare(useString, "sjf") == 0 {
                algorithm = 2
            } else if strings.Compare(useString, "rr") == 0 {
                algorithm = 3
            } else {
                fmt.Println("Error #0: Unable to parse algorithm selection")
                os.Exit(0)
            }
        } else if strings.Contains(element, "quantum") {
            quantum, errAtoi = strconv.Atoi(reInt.FindString(element))
            checkAtoi(errAtoi)
        } else if strings.Contains(element, "process name") {
            processes[processIndex] = after(element, "process name ")
            processIndex++
        } else if strings.Compare(element, "end") == 0 {
            break
        } else {
            fmt.Println("Error #1: Unable to reach end");
            os.Exit(1)
        }
    }

    // Parse each process
    processName := make([] string, processCount)
    arrival := make([] int, processCount)
    burst := make([] int, processCount)
    processIndex = 0
    for _, element := range processes {
        if element != "" {
            processName[processIndex] = strings.Trim(element[0:3], " ")
            arrival[processIndex], errAtoi = strconv.Atoi(strings.Trim(between(element, "arrival", "burst"), " "))
            checkAtoi(errAtoi)

            if strings.Contains(element, "#") {
                burst[processIndex], errAtoi = strconv.Atoi(strings.Trim(between(element, "burst", "#"), " "))
            } else {
                burst[processIndex], errAtoi = strconv.Atoi(strings.Trim(after(element, "burst"), " "))
            }
            checkAtoi(errAtoi)
            processIndex++
        }
    }

    // Write to output file
    outputFile, errFile := os.Create(outputArg)
    checkFile(errFile)
    defer outputFile.Close()

    // Schedule the processes
    wait := make([] int, processCount)
    turnaround := make([] int, processCount)
    mapping := make([] int, processCount)
    if algorithm == 1 {
        fmt.Fprintf(outputFile, "%3d processes\n", processCount)
        fmt.Fprintln(outputFile, "Using First-Come First-Served")

        scheduleName := make([] string, processCount)
        scheduleArrival := make([] int, processCount)
        scheduleBurst := make([] int, processCount)
        copy(scheduleName, processName)
        copy(scheduleArrival, arrival)
        copy(scheduleBurst, burst)
        for i := processCount - 2; i >= 0; i-- {
            for j := 0; j <= i; j++ {
                if scheduleArrival[j] > scheduleArrival[j+1] {
                    tempArrival := scheduleArrival[j]
                    tempBurst := scheduleBurst[j]
                    tempName := scheduleName[j]
                    scheduleArrival[j] = scheduleArrival[j+1]
                    scheduleBurst[j] = scheduleBurst[j+1]
                    scheduleName[j] = scheduleName[j+1]
                    scheduleArrival[j+1] = tempArrival
                    scheduleBurst[j+1] = tempBurst
                    scheduleName[j+1] = tempName
                }
            }
        }

        // Map sorted processes to original processes
        for i := 0; i < processCount; i++ {
            for j := 0; j < processCount; j++ {
                if strings.Compare(scheduleName[j], processName[i]) == 0 {
                    mapping[i] = j
                }
            }
        }

        var i, processInUse, processStart int = 0, 0, 0
        for time := 0; time < runFor; time++ {
            // Process arrives
            for process := 0; process < processCount; process++ {
                if scheduleArrival[process] == time {
                    fmt.Fprintf(outputFile, "Time %3d : %s arrived\n", time, scheduleName[process])
                }
            }

            // Process finishes
            if time == processStart + scheduleBurst[i] {
                processInUse = 0
                fmt.Fprintf(outputFile, "Time %3d : %s finished\n", time, scheduleName[i])

                // Next process
                if i + 1 < processCount {
                    i++
                } else {
                    processInUse = -1
                }
            }
            
            // No processes left or process has not arrived
            if processInUse == -1 || processInUse == 0 && scheduleArrival[i] > time {
                fmt.Fprintf(outputFile, "Time %3d : Idle\n", time)
            }

            // Process is ready
            if processInUse == 0 && scheduleArrival[i] <= time {
                processInUse = 1
                processStart = time
                wait[i] = time - scheduleArrival[i]
                fmt.Fprintf(outputFile, "Time %3d : %s selected (burst %3d)\n", time, scheduleName[i], scheduleBurst[i])
            }
        }

        // Final output
        fmt.Fprintf(outputFile, "Finished at time %3d\n\n", runFor)
        for process := 0; process < processCount; process++ {
            turnaround[process] = burst[process] + wait[mapping[process]]
            fmt.Fprintf(outputFile, "%s wait %3d turnaround %3d\n", processName[process], wait[mapping[process]], turnaround[process]);
        }
    } else if algorithm == 2 {
        fmt.Fprintf(outputFile, "%3d processes\n", processCount)
        fmt.Fprintln(outputFile, "Using preemptive Shortest Job First")

        scheduleName := make([] string, processCount)
        scheduleArrival := make([] int, processCount)
        scheduleBurst := make([] int, processCount)
        copy(scheduleName, processName)
        copy(scheduleArrival, arrival)
        copy(scheduleBurst, burst)
        for i := processCount - 2; i >= 0; i-- {
            for j := 0; j <= i; j++ {
                if scheduleArrival[j] > scheduleArrival[j+1] {
                    tempArrival := scheduleArrival[j]
                    tempBurst := scheduleBurst[j]
                    tempName := scheduleName[j]
                    scheduleArrival[j] = scheduleArrival[j+1]
                    scheduleBurst[j] = scheduleBurst[j+1]
                    scheduleName[j] = scheduleName[j+1]
                    scheduleArrival[j+1] = tempArrival
                    scheduleBurst[j+1] = tempBurst
                    scheduleName[j+1] = tempName
                } else if scheduleArrival[j] == scheduleArrival[j+1] {
                    if scheduleBurst[j] > scheduleBurst[j+1] {
                        tempMap := j
                        tempArrival := scheduleArrival[j]
                        tempBurst := scheduleBurst[j]
                        tempName := scheduleName[j]
                        mapping[j] = j + 1
                        scheduleArrival[j] = scheduleArrival[j+1]
                        scheduleBurst[j] = scheduleBurst[j+1]
                        scheduleName[j] = scheduleName[j+1]
                        mapping[j+1] = tempMap
                        scheduleArrival[j+1] = tempArrival
                        scheduleBurst[j+1] = tempBurst
                        scheduleName[j+1] = tempName
                    }
                }
            }
        }

        // Map sorted processes to original processes
        for i := 0; i < processCount; i++ {
            for j := 0; j < processCount; j++ {
                if strings.Compare(scheduleName[j], processName[i]) == 0 {
                    mapping[i] = j
                }
            }
        }

        processTime := make([] int, processCount)
        readyQueue := make([] int, processCount)
        var shortestBurst, shortestJob int = runFor, 0
        for time := 0; time < runFor; time++ {
            // Process arrives
            for process := 0; process < processCount; process++ {
                if scheduleArrival[process] == time {
                    readyQueue[process] = 1
                    fmt.Fprintf(outputFile, "Time %3d : %s arrived\n", time, scheduleName[process])
                }
            }

            // Process finishes
            if processTime[shortestJob] == scheduleBurst[shortestJob] {
                turnaround[shortestJob] = time - scheduleArrival[shortestJob]
                readyQueue[shortestJob] = -1
                fmt.Fprintf(outputFile, "Time %3d : %s finished\n", time, scheduleName[shortestJob])
            }

            // Look for the shortest job
            var prevShortestJob int = shortestJob
            shortestBurst = runFor
            for i := 0; i < processCount; i++ {
                for j := 0; j < processCount; j++ {
                    if readyQueue[i] >= 1 && readyQueue[j] >= 1 && shortestBurst > scheduleBurst[j] - processTime[j] {
                        shortestBurst = scheduleBurst[j] - processTime [j]
                        shortestJob = j
                    }
                }
            }

            // Indicate whether we switched jobs
            if prevShortestJob != shortestJob && readyQueue[prevShortestJob] > 0 {
                readyQueue[prevShortestJob] = 1
            }

            // Select the process
            if readyQueue[shortestJob] == 1 {
                fmt.Fprintf(outputFile, "Time %3d : %s selected (burst %3d)\n", time, scheduleName[shortestJob], scheduleBurst[shortestJob] - processTime[shortestJob])
                readyQueue[shortestJob] = 2
            } else if readyQueue[shortestJob] == -1 {
                fmt.Fprintf(outputFile, "Time %3d : Idle\n", time)
            }
            processTime[shortestJob]++

            // Compute wait time for unused processes
            for i:= 0; i < processCount; i++ {
                if readyQueue[i] == 1 {
                    wait[i]++
                }
            }
        }

        // Final output
        fmt.Fprintf(outputFile, "Finished at time %3d\n\n", runFor)
        for process := 0; process < processCount; process++ {
            fmt.Fprintf(outputFile, "%s wait %3d turnaround %3d\n", processName[process], wait[mapping[process]], turnaround[mapping[process]]);
        }
    } else if algorithm == 3 {
        fmt.Fprintf(outputFile, "%3d processes\n", processCount)
        fmt.Fprintln(outputFile, "Using Round-Robin")
        fmt.Fprintf(outputFile, "Quantum %3d\n\n", quantum)
        
        scheduleName := make([] string, processCount)
        scheduleArrival := make([] int, processCount)
        scheduleBurst := make([] int, processCount)
        copy(scheduleName, processName)
        copy(scheduleArrival, arrival)
        copy(scheduleBurst, burst)
        for i := processCount - 2; i >= 0; i-- {
            for j := 0; j <= i; j++ {
                if scheduleArrival[j] > scheduleArrival[j+1] {
                    tempArrival := scheduleArrival[j]
                    tempBurst := scheduleBurst[j]
                    tempName := scheduleName[j]
                    scheduleArrival[j] = scheduleArrival[j+1]
                    scheduleBurst[j] = scheduleBurst[j+1]
                    scheduleName[j] = scheduleName[j+1]
                    scheduleArrival[j+1] = tempArrival
                    scheduleBurst[j+1] = tempBurst
                    scheduleName[j+1] = tempName
                } else if scheduleArrival[j] == scheduleArrival[j+1] {
                    if scheduleBurst[j] > scheduleBurst[j+1] {
                        tempMap := j
                        tempArrival := scheduleArrival[j]
                        tempBurst := scheduleBurst[j]
                        tempName := scheduleName[j]
                        mapping[j] = j + 1
                        scheduleArrival[j] = scheduleArrival[j+1]
                        scheduleBurst[j] = scheduleBurst[j+1]
                        scheduleName[j] = scheduleName[j+1]
                        mapping[j+1] = tempMap
                        scheduleArrival[j+1] = tempArrival
                        scheduleBurst[j+1] = tempBurst
                        scheduleName[j+1] = tempName
                    }
                }
            }
        }

        // Map sorted processes to original processes
        for i := 0; i < processCount; i++ {
            for j := 0; j < processCount; j++ {
                if strings.Compare(scheduleName[j], processName[i]) == 0 {
                    mapping[i] = j
                }
            }
        }

        processTime := make([] int, processCount)
        readyQueue := make([] int, processCount)
        var cur, active, mod, quantF int = 0, 0, 0, 0
        for time := 0; time < runFor; time++ {
            // Process arrives
            for process := 0; process < processCount; process++ {
                if scheduleArrival[process] == time {
                    readyQueue[process] = 1
                    active++
                    fmt.Fprintf(outputFile, "Time %3d : %s arrived\n", time, scheduleName[process])
                }
            }

            // Process finishes
            if processTime[cur] == scheduleBurst[cur] {
                turnaround[cur] = time - scheduleArrival[cur]
                readyQueue[cur] = -1
                active--
                if time % quantum == mod {
                    quantF = 1
                } else {
                    quantF = 0
                }
                mod = time % quantum
                fmt.Fprintf(outputFile, "Time %3d : %s finished\n", time, scheduleName[cur])
            }
            // Choose the process
            var prev int = cur
            if (time % quantum == mod || readyQueue[cur] == -1) && time != 0 {
                if cur < processCount - 1 {
                    if readyQueue[cur+1] >= 1 {
                        cur++
                    }
                } else if readyQueue[0] >= 1 {
                    cur = 0
                }

                if (readyQueue[prev] == -1 && quantF == 0) || active == 1 {
                    for i := 0; i < processCount; i++ {
                        if readyQueue[i] >= 1 {
                            cur = i
                            break
                        }
                    }
                }

                // If cur was not changed, then change if there are active processes.
                if prev == cur {
                    for i := 0; i < cur; i++ {
                        if i != cur && readyQueue[i] >= 1 && active >= 1 {
                            cur = i
                        }
                    }
                }
            }

            // Indicate whether we switched jobs
            if prev != cur && readyQueue[cur] > 0 && readyQueue[prev] != -1 {
                readyQueue[prev] = 1
            }

            // Actually select the process
            if (time % quantum == mod || readyQueue[prev] == -1) && readyQueue[cur] >= 1 && scheduleBurst[cur] - processTime[cur] > 0 {
                fmt.Fprintf(outputFile, "Time %3d : %s selected (burst %3d)\n", time, scheduleName[cur], scheduleBurst[cur] - processTime[cur])
                readyQueue[cur] = 2
            } else if readyQueue[cur] == -1 {
                fmt.Fprintf(outputFile, "Time %3d : Idle\n", time)
            }
            processTime[cur]++

            // Compute wait time for unused processes
            for i := 0; i < processCount; i++ {
                if readyQueue[i] == 1 {
                    wait[i]++
                }
            }
        }

        // Final output
        fmt.Fprintf(outputFile, "Finished at time %3d\n\n", runFor)
        for process := 0; process < processCount; process++ {
            fmt.Fprintf(outputFile, "%s wait %3d turnaround %3d\n", processName[process], wait[mapping[process]], turnaround[mapping[process]]);
        }
    } else {
        fmt.Println("Error #2: Attempting to use invalid algorithm")
        os.Exit(2)
    }
}

import pygame#,sys
import sys
pygame.init()

width = 900
height = 700
screenDim = (width,height)

screen = pygame.display.set_mode(screenDim)

pygame.display.set_caption("My First Game")

grassImage = pygame.image.load("grass.png").convert()
screen.blit(grassImage,(0,0))

finished = False
while finished == False:
    #processing all the events
    for event in pygame.event.get(): # event1, event2,..
        #do appropriate things with events
        if event.type == pygame.QUIT:
            finished = True
            pygame.quit()
            sys.exit()
            
    pygame.display.flip()#Update method/load next frame
    
#pygame.quit()

import xml.etree.ElementTree as ET

tree = ET.parse('meals.xml')

# root.tag: 'meals'
# root.attrib: '{}'
meals = tree.getroot()

# take precedence in side dishes
side_dishes = []
main_dishes = []

# loops through 'breakfast', 'lunch', 'dinner'
for meal_time in meals:
    # if side exists, get all the side dishes
    if meal_time.find('side') is not None:
        side_dishes.append(meal_time.find('side').find('dish').text)
    # else, get the main dish
    else:
        main_dishes.append(meal_time.find('main').find('dish').text)

print "Side dishes: " + str(side_dishes)
print "Main dishes: " + str(main_dishes)

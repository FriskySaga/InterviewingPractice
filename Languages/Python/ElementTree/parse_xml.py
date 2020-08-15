# import xml.etree.ElementTree as ET
from xml.etree.ElementTree import parse

tree = parse('meals.xml')

# root.tag: 'meals'
# root.attrib: '{}'
rootMeals = tree.getroot()

# take precedence in side dishes
side_dishes = []
main_dishes = []

# loops through 'breakfast', 'lunch', 'dinner'
for meal_time in rootMeals:
    # if side exists, get all the side dishes
    if meal_time.find('side') is not None:
        side_dishes.append(meal_time.find('side').find('dish').text)
    # else, get the main dish
    else:
        main_dishes.append(meal_time.find('main').find('dish').text)

print(f'Side dishes: {side_dishes}')
print(f'Main dishes: {main_dishes}')


# Dig deep to find the Froot Loops
cerealBrandNode = rootMeals.find('breakfast').find('main').find('brand')
print(cerealBrandNode.text)

# Then change Froot Loops to Frosty Flakes, and then change it back
cerealBrandNode.text = 'Frosty Flakes'
tree.write('meals.xml')
cerealBrandNode.text = 'Froot Loops'
tree.write('meals.xml')



discount_overall = 0
discount = 0
# input
red = int(input("Enter number of red roses purchased: "))
white = int(input("Enter number of white roses purchased: "))
tulips = int(input("Enter number of tulips purchased: "))
season = input("Enter which season it is :")
holiday = input("is it holiday today??")


# calculating conditional price after discounts
total_flowers = red + white + tulips
if season == 'spring' or season == 'summer':
    price_red = int(red) * 2
    price_white = int(white) * 4.10
    price_tulips = int(tulips) * 2.50

if season == 'autumn' or season == 'winter':
    price_red = int(red) * 3.75
    price_white = int(white) * 4.50
    price_tulips = int(tulips) * 4.15

# calculating total price
total_price = float(price_red) + float(price_white) + float(price_tulips) + 2

# holiday discounts
if holiday == 'y':
    increment = float(total_price) / 6.63
    total_price = float(total_price) + float(increment)


if season == 'spring' and int(tulips) > 7:
    discount = float(total_price) / 20

if season == 'winter' and int(white) > 10:
    discount = float(total_price) / 10

if int(total_flowers) > 20:
    discount_overall = float(total_price) / 5

final_price = float(total_price) - (float(discount) + float(discount_overall))
print("You have to pay : ", final_price)

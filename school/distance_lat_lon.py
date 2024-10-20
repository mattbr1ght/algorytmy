from math import sin, cos, sqrt, asin, radians
import re

def dms2dd(lat):
    deg, minutes, seconds, direction =  re.split('[°\'"]', lat)
    print(deg,minutes,seconds, sep=":")
    return (float(deg) + float(minutes)/60 + float(seconds)/(60*60)) * (-1 if direction in ['W', 'S'] else 1)

R = 6371

lat = [0,0]
lon = [0,0]
'''
for i in range(2):
    print("#", i+1)
    lat[i] = dms2dd(input("Podaj szerokość geograficzną: "))
    lon[i] = dms2dd(input("Podaj długość geograficzną: "))

lat[0] = radians(52.2296756)
lon[0] = radians(21.0122287)

# Point two
lat[1] = radians(52.406374)
lon[1] = radians(16.9251681)
'''

lat[0] = dms2dd("52°12'37.6\"N")
lon[0] = dms2dd("21°00'24.7\"E")

lat[1] = dms2dd("5°16'32.7\"S")
lat[1] = dms2dd("60°02'31.1\"W")

dlon = lon[1] - lon[0]
dlat = lat[1] - lat[0]
a = (sin(dlat/2))**2 + cos(lat[0]) * cos(lat[1]) * (sin(dlon/2))**2
c = 2 * asin(sqrt(a))
distance = R * c

print("Dystans: ", distance, "km")

# Author Melody
# Data 2021-06-03 16:27:40

import pandas as pd
import geopy.distance


# Pytest is an automated testing module on Python,Use Pytest to test the legitimacy on Bikeshare Data
# import pytest as pt

# Coords is a data structures to save How Bikeshare Date,Coord just like a List


def getStartEndCoords():
    # load CSV File by using pandas API
    filename = "2019.7-2020.3-Bikeshare-Los_Angeles.csv"
    df = pd.read_csv(filename, sep=",", index_col='Ending Station ID', low_memory=False)
    # Created  a list, here in the interest of saving time,as the csv will not change
    # Numbers represents the Bikeshare stations ID
    allStations = [3005, 3006, 3007, 3008, 3009, 3010, 3011, 3014, 3016, 3018, 3019, 3020, 3021, 3022, 3023, 3024,
                   3025, 3026, 3027, 3028, 3029, 3030, 3031, 3032, 3033, 3034, 3035, 3036, 3037, 3038, 3039, 3040, 3042,
                   3045, 3046, 3047, 3048, 3049, 3051, 3052, 3053, 3054, 3055, 3056, 3057, 3058, 3059, 3060, 3062, 3063,
                   3064, 3065, 3066, 3067, 3068, 3069, 3074, 3075, 3076, 3077, 3078, 3079, 3080, 3081, 3082, 4108]
    # geoCodeEnd meaning geography ID just like 3005 -> 7th & Flower
    geoCodeEnd = []
    for station in allStations:
        temp = []
        # freq -> frequency,frequency must be an INT Type
        freq = df.at[float(station), "Ending Station Latitude"].size
        assert type(freq) == int
        lat = (df.at[float(station), "Ending Station Latitude"]).values[0]
        lng = (df.at[float(station), "Ending Station Longitude"]).values[0]
        # Determining data legitimacy， NaN -> Not a Number
        if str(lat) != 'NaN' and str(lng) != 'NaN':
            temp.append([lat, lng])
            temp.append(freq)
            geoCodeEnd.append(temp)
    dfS = pd.read_csv(filename, sep=",", index_col='Starting Station ID', low_memory=False)
    geoCodeStart = []
    for station in allStations:
        tempS = []
        freqS = dfS.at[float(station), "Starting Station Latitude"].size
        assert type(freqS) == int
        lat = (dfS.at[float(station), "Starting Station Latitude"]).values[0]
        lng = (dfS.at[float(station), "Starting Station Longitude"]).values[0]
        if str(lat) != 'NaN' and str(lng) != 'NaN':
            tempS.append([lat, lng])
            tempS.append(freqS)
            geoCodeStart.append(tempS)
    return geoCodeEnd, allStations, geoCodeStart


# This will calculate the usage of the users
def getRegularRiders():
    filename = "2019.7-2020.3-Bikeshare-Los_Angeles.csv"
    df = pd.read_csv(filename, sep=",", low_memory=False)
    a = df.loc[df['Passholder Type'] != "Walk-up"]
    return len(a.index) / 182  # 182 is the number of days in the given period minus weekends and holidays


# This will count the Average distance of the users
def avgDistance():
    filename = "2019.7-2020.3-Bikeshare-Los_Angeles.csv"
    df = pd.read_csv(filename, sep=",", low_memory=False)
    df = df[["Duration", "Starting Station Latitude", "Starting Station Longitude", "Ending Station Latitude",
             "Ending Station Longitude"]]
    # Distance calculation modified method from StackOverflow
    sum = 0
    count = 0
    time = 0
    for index, row in df.iterrows():
        lat1 = row["Starting Station Latitude"]
        lat2 = row["Ending Station Latitude"]
        lon1 = row["Starting Station Longitude"]
        lon2 = row["Ending Station Longitude"]
        if str(lat1) != 'nan' and str(lat2) != 'nan' and str(lon1) != 'nan' and str(lon2) != 'nan':
            coords_1 = (lat1, lon1)
            coords_2 = (lat2, lon2)
            dist = geopy.distance.geodesic(coords_1, coords_2).miles
            if dist > 0:
                time = time + row["Duration"]
                sum = sum + dist
                count = count + 1
    return (sum / count), (time / count)


# This will calculate User`s passes type
def pieChartPassHolder():
    filename = "2019.7-2020.3-Bikeshare-Los_Angeles.csv"
    df = pd.read_csv(filename, sep=",", low_memory=False)
    df = df[["Passholder Type"]]
    w = len((df.loc[df['Passholder Type'] == "Walk-up"]).index)
    f = len((df.loc[df['Passholder Type'] == "Flex Pass"]).index)
    m = len((df.loc[df['Passholder Type'] == "Monthly Pass"]).index)
    s = len((df.loc[df['Passholder Type'] == "Staff Annual"]).index)
    return [w, f, m, s]


# This will calculate whether the user is a one-way or round trip
def pieChartTripRoute():
    filename = "2019.7-2020.3-Bikeshare-Los_Angeles.csv"
    df = pd.read_csv(filename, sep=",", low_memory=False)
    df = df[["Trip Route Category"]]
    o = len((df.loc[df["Trip Route Category"] == "One Way"]).index)
    r = len((df.loc[df["Trip Route Category"] == "Round Trip"]).index)
    return [o, r]


# this will show a line to represent the Relationship between temperature and number of bicycles lent
def lineByMonth():
    totals = {7: 0, 8: 0, 9: 0, 10: 0, 11: 0, 12: 0, 1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0}
    filename = "2019.7-2020.3-Bikeshare-Los_Angeles.csv"
    df = pd.read_csv(filename, sep=",", converters={'Start Time': pd.to_datetime}, low_memory=False)
    for index, row in df.iterrows():
        totals[((row["Start Time"]).month)] += 1
    return totals

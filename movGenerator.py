import json
import time
import random

with open('data1.json', 'r+') as f:
    data = json.load(f)
    sensor = ["detected", "not detected", "away"]
    mesa = [1, 2, 3, 4, 5]

    while(1):
        mesaTmp = random.choice(mesa)
        movTmp = random.choice(sensor)

        temp = len(data["mesa" + str(mesaTmp)]["sensor"]) 
        data["mesa" + str(mesaTmp)]["sensor"]= movTmp

        f.seek(0)
        json.dump(data, f)
        f.truncate()
        time.sleep(5)

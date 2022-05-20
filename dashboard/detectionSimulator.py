import json
import time
import random

file = open('data.json', 'r+')
data = json.load(file)
sensor = ["Livre", "Ocupado"]
mesa = [0, 1, 2, 3, 4]

while(1):
    mesaTmp = random.choice(mesa)
    movTmp = random.choice(sensor)
    # print(mesaTmp)
    # print(movTmp)
    data["leic"][mesaTmp]["sensor"] = movTmp

    file.seek(0)
    json.dump(data, file)
    file.truncate()
    time.sleep(5)

file.close()
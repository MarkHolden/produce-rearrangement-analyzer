def PrintHistogram():
    print("You printed a histogram!")

def PrintFrequencies():
    print("\nProduce Item Frequencies")
    for k, v in sorted(GetProduceDict().items(), key=lambda x: x[1], reverse=True):
        print("Item:", f'{k:16}', "\tQuantity:", v)


def GetProduceDict() -> dict:
    produceList = open("ProduceInput.txt")
    produceDict = {}
    for inputString in produceList:
        produce = inputString.rstrip('\n')
        if produce in produceDict:
            produceDict[produce] = produceDict[produce] + 1
        else:
            produceDict[produce] = 1
    return produceDict
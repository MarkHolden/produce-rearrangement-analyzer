def SaveHistogramData():
    """Saves Histogram data to frequency.dat file in the format:
    Peaches 5
    Apples 4
    Radishes 3
    """

    frequencyFile = open("frequency.dat", "w+")
    for k, v in sorted(GetProduceDict().items(), key=lambda x: x[1], reverse=True):
        frequencyFile.write("{} {}\n".format(k, v))

def PrintFrequencies():
    """Prints the Frequencies of all produce items in the format:
    Item: Peaches           Quantity: 5
    Item: Apples             Quantity: 4
    Item: Radishes          Quantity: 3
    """

    print("\nProduce Item Frequencies")
    for k, v in sorted(GetProduceDict().items(), key=lambda x: x[1], reverse=True):
        print("Item:", f'{k:16}', "\tQuantity:", v)

def GetItemFrequency(searchTerm: str) -> int:
    """Gets the freqency of an item by name.

    searchTerm: str     search term for which to get the frequency.

    returns: int        freqency of the item.
    """

    produceDict = GetProduceDict()
    return produceDict[searchTerm] if searchTerm in produceDict else 0

def GetProduceDict() -> dict:
    """Gets a dictionary of the produce and frequency.

    returns: dict       dictionary of the produce name and it's frequency
    """

    produceList = open("ProduceInput.txt")
    produceDict = {}
    for inputString in produceList:
        produce = inputString.rstrip('\n')
        if produce in produceDict:
            produceDict[produce] = produceDict[produce] + 1
        else:
            produceDict[produce] = 1
    return produceDict
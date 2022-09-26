class Solution:
    def romanToInt(self, roman_string: str) -> int:
        myDict = {}
        myDict["I"] = 1
        myDict["V"] = 5
        myDict["X"] = 10
        myDict["L"] = 50
        myDict["C"] = 100
        myDict["D"] = 500
        myDict["M"] = 1000
    
        integer = 0
        i = 0
    
        while i < len(roman_string):
            if roman_string[i] == "I":
                if i + 1 < len(roman_string) and (roman_string[i+1] == "X" or roman_string[i+1] == "V"):
                    integer += myDict[roman_string[i+1]] - myDict[roman_string[i]]
                    i += 1
                else:
                    integer += myDict[roman_string[i]]
            elif roman_string[i] == "X":
                if i + 1 < len(roman_string) and (roman_string[i+1] == "L" or roman_string[i+1] == "C"):
                    integer += myDict[roman_string[i+1]] - myDict[roman_string[i]]
                    i += 1
                else:
                    integer += myDict[roman_string[i]]
            elif roman_string[i] == "C":
                if i + 1 < len(roman_string) and (roman_string[i+1] == "D" or roman_string[i+1] == "M"):
                    integer += myDict[roman_string[i+1]] - myDict[roman_string[i]]
                    i += 1
                else:
                    integer += myDict[roman_string[i]]
            else:
                integer += myDict[roman_string[i]]
            i += 1
    

        return integer
        
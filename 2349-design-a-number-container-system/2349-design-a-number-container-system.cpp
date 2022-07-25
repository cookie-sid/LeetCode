class NumberContainers {
public:
    
    map<int,int> indToNum;
    map<int,map<int,int>> numToInd;
    
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indToNum.find(index) != indToNum.end()) {
            numToInd[indToNum[index]][index] = 0;
            indToNum[index] = number;
            numToInd[number][index] = 1;
        }
        else {
            indToNum[index] = number;
            numToInd[number][index] = 1;
        }
    }
    
    int find(int number) {
        for(auto x : numToInd[number]) {
            if(x.second != 0) {
                return x.first;
            }
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
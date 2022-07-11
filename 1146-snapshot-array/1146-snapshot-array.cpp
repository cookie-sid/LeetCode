class SnapshotArray {
public:
    
    vector<int> v;
    int totalSnaps = 0;
    bool changeAfterSnap = false;
    vector<vector<pair<int,int>>> snaps;
    int changes = 0;
    vector<int> snapIds;
    
    SnapshotArray(int length) {
        for(int i = 0; i < length; i++) {
            v.push_back(0);
            snaps.push_back({});
        }

    }
    
    void set(int index, int val) {
        if(v[index] != val) {
            changes += 1;
            v[index] = val;
            snaps[index].push_back(make_pair(val,changes));
            changeAfterSnap = true;
        }
    }
    
    int snap() {
        snapIds.push_back(changes);
        if(changeAfterSnap) {
            changeAfterSnap = false;
        }
        return snapIds.size() - 1;
    }
    
    int get(int index, int snap_id) {
        int ch = snapIds[snap_id];
        int top = snaps[index].size() - 1;
        while(top >= 0 and snaps[index][top].second > ch) {
            top--;
        }
        if(top == -1) {
            return 0;
        }
        return snaps[index][top].first;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
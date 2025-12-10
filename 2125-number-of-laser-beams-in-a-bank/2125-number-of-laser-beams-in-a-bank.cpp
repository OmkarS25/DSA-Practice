class Solution {
public:
    int countDevices(string& binary) {
        int count = 0;
        for (char b : binary) count += b-'0';
        return count;
    }

    int numberOfBeams(vector<string>& bank) {
        vector<int> devices;
        for(auto row : bank) 
            devices.push_back(countDevices(row));
        int beams = 0, n = devices.size();
        for(int i=0; i<n; i++){
            int j = i+1;
            while(j<n){
                beams += devices[i] * devices[j];
                if(devices[j] == 0) j++;
                else break;
            }
        }
        return beams;
    }
};
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n=target.size();
        int m=arr.size();

        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        int cnt=0;
        for(int i=0;i<n;i++){
            if(target[i]==arr[i]){
                cnt++;
            }
        }
        if(cnt==n){
            return true;
        }
        return false;
    }
};

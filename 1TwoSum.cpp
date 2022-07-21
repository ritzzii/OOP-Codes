1st method:
--------------------------------------
class Solution 
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
    unordered_map<int, int> hash;
	
    vector<int> result;
        
	for (int i = 0; i < numbers.size(); i++) 
    {
		int numberToFind = target - numbers[i];

        if (hash.find(numberToFind) != hash.end()) 
        {
            
			result.push_back(hash[numberToFind]);
			result.push_back(i);			
			return result;
		}

        hash[numbers[i]] = i;
	}
	return result;
    }
};
//Time Complexity:O(n)
//Space Complexity:O(n)

2nd method:
--------------------------------------
class Solution 
{
public:
  vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++)
            v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        int i=0;
        int j=v.size()-1;
        int idx1=0;
        int idx2=0;
        while(i<j)
        {
            if(v[i].first+v[j].first==target)
            {
                idx1=v[i].second;
                idx2=v[j].second;
                break;
                
            }
            if(v[i].first+v[j].first<target)
                i++;
            if(v[i].first+v[j].first>target)
                j--;
    }
        return {idx1,idx2};
    }
//Time Complexity:O(nlogn)
//Space Complexity:O(n)

	
/*

public int[] twoSum(int[] numbers, int target) {
    int[] result = new int[2];
    Map<Integer, Integer> map = new HashMap<Integer, Integer>();
    for (int i = 0; i < numbers.length; i++) {
        if (map.containsKey(target - numbers[i])) {
            result[1] = i;
            result[0] = map.get(target - numbers[i]);
            return result;
        }
        map.put(numbers[i], i);
    }
    return result;
}

*/
	

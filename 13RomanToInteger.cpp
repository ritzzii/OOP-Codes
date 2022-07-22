class Solution {
public:
    int romanToInt(string s) 
    {
       if (s.empty()) 
           return 0;
        
        unordered_map <char, int> m =
        {
            {'I', 1} , {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
       int result{0};
        for(int i = 0; i<s.length() - 1; i++)
        {
            if (m[s[i]] < m[s[i+1]])
            {
                result = result - m [s[i]];
            }
            else
            {
                result = result + m[s[i]];
            }
        }
        result = result + m[s.back()];
        
        return result;        
    }
};


/*
public int romanToInt(String s) {
        Map<Character, Integer> map = new HashMap<>();
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);
        char[] chars = s.toCharArray();
        int result = 0;
        int i = 0, j = 1;
        for(; j < chars.length; i++, j++) {
            if (map.get(chars[i]) >= map.get(chars[j])) {
                result += map.get(chars[i]);
            } else {
                result -= map.get(chars[i]);
            }
        }
        result += map.get(chars[i]);
        return result;
    }
    
    */

/*

int romanToInt(string s) {
		unordered_map<char, int> charToInt = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
		int result = 0;
		int index = s.length() - 1;
		int preInt = 0;
		while (index >= 0)
		{
			char ch = s[index];
			int curInt = charToInt[ch];
			if (curInt >= preInt)
				result += curInt;
			else
				result -= curInt;
		
			preInt = curInt;
			index--;
		}
			
		return result;
	}
  
  */

/*

public int romanToInt(String s) {
     int sum=0;
    if(s.indexOf("IV")!=-1){sum-=2;}
    if(s.indexOf("IX")!=-1){sum-=2;}
    if(s.indexOf("XL")!=-1){sum-=20;}
    if(s.indexOf("XC")!=-1){sum-=20;}
    if(s.indexOf("CD")!=-1){sum-=200;}
    if(s.indexOf("CM")!=-1){sum-=200;}
    
    char c[]=s.toCharArray();
    int count=0;
    
   for(;count<=s.length()-1;count++){
       if(c[count]=='M') sum+=1000;
       if(c[count]=='D') sum+=500;
       if(c[count]=='C') sum+=100;
       if(c[count]=='L') sum+=50;
       if(c[count]=='X') sum+=10;
       if(c[count]=='V') sum+=5;
       if(c[count]=='I') sum+=1;
       
   }
   
   return sum;
    
}

*/


/*  3 ms 

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int prev = mapping(s[0]);
        // Idea: Traverse the string and maintain the value of previous bit
        // If previous value is lower than current value --> subtraction
        for (int i = 1; i != s.size(); i++) {
            int curr = mapping(s[i]);
            if (prev < curr) {
                ans -= prev;
            }
            else {
                ans += prev;
            }
            prev = curr;
        }
        ans += prev;
        return ans;
    }
    
private:
    int mapping(char ch) {
        switch(ch) {
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
            default : return 0;
        }
    }
};

*/


/*

class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        int i=0;
        int n=s.length();
        for(i=0;i<n;i++)
        {
            if(s[i]=='M')
            {
                ans+=1000;
            }
            if(s[i]=='D')
            {
                ans+=500;
            }
            if(s[i]=='C')
            {
                if(i+1<n && (s[i+1]=='M' || s[i+1]=='D'))
                {
                    if(s[i+1]=='M')
                    {
                        ans+=900;
                    }
                    else
                        ans+=400;
                    
                    i++;
                    continue;
                }
                else
                    ans+=100;
                
            }
            if(s[i]=='L')
            {
                ans+=50;
            }
            if(s[i]=='X')
            {
                 if(i+1<n && (s[i+1]=='C' || s[i+1]=='L'))
                {
                    if(s[i+1]=='C')
                    {
                        ans+=90;
                    }
                    else
                        ans+=40;
                    
                    i++;
                    continue;
                }
                else
                    ans+=10;
            }
            if(s[i]=='V')
            {
                ans=ans+5;
            }
            if(s[i]=='I')
            {
                if(i+1<n && (s[i+1]=='X' || s[i+1]=='V'))
                {
                    if(s[i+1]=='X')
                    {
                        ans+=9;
                    }
                    else
                        ans+=4;
                    
                    i++;
                    continue;
                }
                else
                    ans+=1;
            }
        }
        return ans;
    }
};

*/
/* 4 ms
class Solution {
public:
    int value (char ch){
        int ans;
        switch(ch){
            case 'I':ans =1; break;
            case 'V':ans=5; break;
            case 'X':ans=10; break;
            case 'L':ans=50; break;
            case 'C':ans=100; break;
            case 'D':ans=500; break;
            case 'M':ans=1000; break;}
        return ans;
    }
    int priority(char ch){
        int ans;
        switch(ch){
                
                case 'I':ans =7; break;
                case 'V':ans=6; break;
                case 'X':ans=5; break;
                case 'L':ans=4; break;
                case 'C':ans=3; break;
                case 'D':ans=2; break;
                case 'M':ans=1; break;
        }    
        return ans;
    }
    int romanToInt(string s) {
        int num=0;
        int n = s.length()-1;
        for (int i=0;i<n;i++){

            int val = value(s[i]);
            if(priority(s[i])>priority(s[i+1]))
            {
                val *=(-1);
            }
            num+=val;
        }
        num = num + value(s[n]);
        
        return num;
        
    }
};

*/

/* less memory - 5800KB  and less time 10 ms

class Solution {
public:
    int convert(char str)
    {
        if(str=='I')
        {
            return 1;
        }
        else if(str=='V')
        {
            return 5;
        }
        else if(str=='X')
        {
            return 10;
        }
        else if(str=='L')
        {
            return 50;
        }
       else if(str=='C')
        {
            return 100;
        }
        else if(str=='D')
        {
            return 500;
        }
        return 1000;
    }
    int romanToInt(string s) {
        int n=s.length();
        int ans=convert(s[n-1]);
        int i=n-2;
        while(i>=0)
        {
            if(convert(s[i])<convert(s[i+1]))
            {
                ans-=convert(s[i]);
            }
            else{
                ans+=convert(s[i]);
            }
            i--;
        }
        return ans;
    }
};
*/


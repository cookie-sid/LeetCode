bool dfs(string s, string p, int l1, int l2)
{
    //base cases
	//if both strings are empty it will be a match so we return true
    if (l1 == 0 && l2 == 0)
    {
        return true;
    }
	//if input string is empty
    if (l1 == 0)
    {
		/*if length of pattern is 1 while input is empty it cannot be a match since a pattern may be '.','*' or 'a-z'
		now let us understand case by case :
		. -> matches with a single character but since input is empty so no match
		similarily for a-z no match
		* -> it does not have any preceeding element as length is one so no match*/
        if (l2 == 1)
        {
            return false;
        }
		/*here pattern length>1
		if last character is not * it can not be a match*/
        else if (p[l2 - 1] != '*')
        {
            return false;
        }
		/*here last character is * and length>1
		since * can match 0 or more of preceding element 
			here since first string is empty * will match zero occurences of preceding element so we 
			will recur for rec(input,patt-2)*/
        else
        {
            return dfs(s, p, l1, l2 - 2);
        }
    }
	/*if input is non-empty and pattern is empty then no match*/
    if (l2 == 0)
    {
        return false;
    }

    //main body
	/*if last character of pattern is either . or matches with last character of input then recur for rec(in-1,pat-1)*/
    if (s[l1 - 1] == p[l2 - 1] || p[l2 - 1] == '.')
    {
        return dfs(s, p, l1 - 1, l2 - 1);
    }
	
	/*if last character of pattern is * */
    else if (p[l2 - 1] == '*')
    {
        if (p[l2 - 2] == s[l1 - 1] || p[l2 - 2] == '.')
        {
		//it can match will either zero occurences of preceding char -> recur for(in,pat-2)
		//it can match with last char ->recur for rec(in-1,pat)
            return dfs(s, p, l1 - 1, l2) || dfs(s, p, l1, l2 - 2);
        }
        else
        {
            return dfs(s, p, l1, l2 - 2);
        }
    }
    return false;
}

class Solution {
public:  
    bool isMatch(string s, string p) {
        
        return dfs(s,p,s.length(),p.length());
        
    }
};
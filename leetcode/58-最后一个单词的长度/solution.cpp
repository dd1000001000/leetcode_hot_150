class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        s = ' ' + s;
        int pos = s.size() - 1;
        while (s[pos] == ' ')
        {
            --pos;
        }

        int space = pos - 1;
        while (s[space] != ' ')
        {
            --space;
        }

        return pos - space;
    }
};

int binSearch(const int s[], const int size, const int target)
{
    int begin = 0, end = size - 1;
    while(1) {
        if (begin >= end) {
            if (s[begin] == target)
                return begin;
            return -1;
        }
        if (s[(end - begin) / 2 + begin] <= target) {
            if (end - begin == 1) {
                if (s[end] == target)
                    return end;
                if (s[begin] == target)
                    return begin;
                return -1;
            }
            begin = (end - begin) / 2 + begin;
            continue;
        }
        else {
            end = ((end - begin) / 2) - 1 + begin;
        }
    }
}                                 
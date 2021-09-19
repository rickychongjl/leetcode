// https://leetcode.com/problems/backspace-string-compare/submissions/
var backspaceCompare = function (s, t) {
    if (s.length == 1 && t.length == 1) {
        if (s[0] != '#' && t[0] != '#') {
            return s[0] == t[0];
        }
    }
    let right = 0;
    var sStack = "";
    //for s
    while (right < s.length) {
        if (s[right] == '#') {
            sStack = sStack.substring(0, sStack.length - 1)
        } else {
            sStack+=s[right];
        }
        right++;
    }
    right = 0;
    var tStack = "";
    //fr s
    while (right < t.length) {
        if (t[right] == '#') {
            tStack = tStack.substring(0, tStack.length - 1)
        } else {
            tStack+=t[right];
        }
        right++;
    }
    return (sStack === tStack);
};
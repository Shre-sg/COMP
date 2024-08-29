def MinWindowSubstring(strArr):
    N = strArr[0]
    K = strArr[1]

    if not N or not K:
        return ""

#Dictionary to keep count of all unique characters in K
    dict_k = {}
    for char in K:
        dict_k[char] = dict_k.get(char, 0) + 1

    required = len(dict_k)
    left, right = 0, 0
    formed = 0
    window_counts = {}
    varOcg = float("inf"), None, None  # (window length, left, right)

    while right < len(N):
        character = N[right]
        window_counts[character] = window_counts.get(character, 0) + 1

        if character in dict_k and window_counts[character] == dict_k[character]:
            formed += 1

        while left <= right and formed == required:
            character = N[left]

#Save the smallest window
            if right - left + 1 < varOcg[0]:
                varOcg = (right - left + 1, left, right)

            window_counts[character] -= 1
            if character in dict_k and window_counts[character] < dict_k[character]:
                formed -= 1

            left += 1

        right += 1

    return "" if varOcg[0] == float("inf") else N[varOcg[1]:varOcg[2] + 1]

#Example usage:
print(MinWindowSubstring(["aaabaaddae", "aed"]))  # Output: dae
print(MinWindowSubstring(["aabdccdbcacd", "aad"]))  # Output: aabd
print(MinWindowSubstring(["ahffaksfajeeubsne", "jefaa"]))  # Output​⬤
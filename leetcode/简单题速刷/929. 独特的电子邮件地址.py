from typing import List

class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        result = set()
        for email in emails:
            name, domain = email.split("@")
            domain = '@'+domain
            name = name.replace(".", "")
            if name.find("+")>=0:
                name = name[:name.find("+")]
            temp = name + domain
            result.add(temp)
        return len(result)
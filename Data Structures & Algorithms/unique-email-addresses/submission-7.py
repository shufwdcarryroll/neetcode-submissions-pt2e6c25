class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        uniqueEmails = set()

        for email in emails :
            atPos = email.find('@')
            local = email[0:atPos]
            domain = email[atPos:]

            cleanLocal = ""

            for c in local :
                if c == '+' :
                    break
                if c != '.' :
                    cleanLocal += c

            finalEmail = cleanLocal + domain;
            uniqueEmails.add(finalEmail);

        return len(uniqueEmails);

import math
class Solution:
	def NthTerm(self, N):

		# Code here
            i=0
            while True:
                if self.iSprime(N+i) or self.iSprime(N-i):
                    return i
                i+=1
            return i

 def iSprime(self, n):
            if n==1:
                return 0
            elif n<=3:
                return 1
            
            for i in range(2, int(n**0.5)+1):
                if n%i==0:
                    return 0
            return 1

def isprime(x):
    for i in range(2,x):
        if x%i==0:
            return False
    return True


primes=[]
isp=[True]*100020
    if isp[i]:
        primes.append(i)


def g(n):
    ans=0
    for i in range(0,n):
        ans+=n*primes[i]
    return ans

def f(n):
    ans=0
    for i in range(0,n):
        ans+=(n-i-1)*primes[i]
    return ans

for i in range(3,len(primes)):
    print(1.0*f(i)/g(i))

try:
    while(1):
        n=int(input())
        print(n)
        c=1
        strat=2*n+1
        for i in range(1,n+1):
            c*=strat
            strat-=1
        for i in range(1,n+1):
            c/=i
            
        print(int(c/(2*n+1)))
    
except:
    pass

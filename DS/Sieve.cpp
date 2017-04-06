void sieve(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
      if (prime[p] == true)
      {
         for (int i=p*p; i<=n; i=i+p)
            prime[i] = false;
      }
    }


    for (int k=2; k<=n; k++)
    {
      if (prime[k])  cout<<k<< " ";
    }
}

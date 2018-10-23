inline long long multi(long long x,long long y,long long mod)
{
long long tmp=(x*y-(long long)((long double)x/mod*y+1.0e-8)*mod);
return tmp<0 ? tmp+mod : tmp;
}

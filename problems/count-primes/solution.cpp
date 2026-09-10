class Solution {
public:
    int countPrimes(int n) {

        if (n <= 2)
            return 0;

        vector<char> isPrime(n, 1);

        isPrime[0] = 0;
        isPrime[1] = 0;

        // Sirf odd numbers ko sieve karo
        for (int i = 3; 1LL * i * i < n; i += 2)
        {
            if (isPrime[i])
            {
                // i*i se start, sirf odd multiples
                for (long long j = 1LL * i * i; j < n; j += 2LL * i)
                {
                    isPrime[j] = 0;
                }
            }
        }

        // 2 khud prime hai
        int count = 1;

        // Sirf odd numbers count karo
        for (int i = 3; i < n; i += 2)
        {
            if (isPrime[i])
                count++;
        }
        return count;
    }
};
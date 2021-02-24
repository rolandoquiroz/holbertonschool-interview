   minCoins = total
   if total in coins:
     return 1
   else:
      for i in [c for c in coins if c <= total]:
         numCoins = 1 + recMC(coins,total-i)
         if numCoins < minCoins:
            minCoins = numCoins
   return minCoins
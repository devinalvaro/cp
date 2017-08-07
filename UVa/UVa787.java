import java.math.*;
import java.util.*;

class Main {
    public static void main(String[] args) {
        (new UVa787()).solve();
    }
}

class UVa787
{
    private final Scanner s = new Scanner(System.in);

    public void solve()
    {
        while (s.hasNext()) {
            List<BigInteger> sequence = new ArrayList<BigInteger>();

            int n;
            while (s.hasNext() && (n = s.nextInt()) != -999999) {
                sequence.add(BigInteger.valueOf(n));
            }

            BigInteger result = sequence.get(0);

            for (int i = 0, sz = sequence.size(); i < sz; i++) {
                BigInteger current = sequence.get(i);
                result = result.max(current);

                for (int j = i + 1; j < sz; j++) {
                    current = current.multiply(sequence.get(j));
                    result = result.max(current);
                }
            }

            System.out.println(result);
        }
    }
}

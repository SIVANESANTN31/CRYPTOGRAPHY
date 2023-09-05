#include<stdio.h>
#include<math.h>

void encrypt();
void decrypt();
long int findGCD(long int, long int);
long int multipicative_inverse(long int, long int);
void key_pair(long int e, long int n, long int d) {
  printf("\nEncryption key(e,n):%ld , %ld\n", e, n);
  printf("\nDecryption key(d,n):%ld , %ld\n", d, n);
}
void encrypt() {
  long int m, p, q, n, fn, e = 2, temp, d, ct;
  printf("\nEnter your message to encrypt : ");
  scanf("%d", &m);
  printf("\nEnter prime numbers p : ");
  scanf("%ld", & p);
  printf("\nEnter prime numbers q : ");
  scanf("%ld", & q);
  n = p * q;
  fn = (p - 1) * (q - 1);
  temp = findGCD(e, fn);
  while (temp != 1) {
    e++;
    temp = findGCD(e, fn);
  }
  d = multipicative_inverse(fn, e);
  if (d == 0) {
    printf("\nRSA is not possible for given p and q.\n");
  }
  ct = fmod(pow(m, e), n);
  key_pair(e, n, d);
  printf("\nEncrypted text:\t%ld\n", ct);
}
void decrypt() {
  long int m, d, ct, n;
  printf("\nEnter message to decrypt : ");
  scanf("%ld", & ct);
  printf("\nEnter key pair(d,n) : ");
  scanf("%ld %ld", & d, & n);
  m = fmod(pow(ct, d), n);
  printf("\nDecrypted message :\t%ld", m);
}
long int multipicative_inverse(long int m, long int b) {
  long int a1 = 1, a2 = 0, a3 = m, b1 = 0, b2 = 1, b3 = b, t1, t2, t3, q;
  top:
    if (b3 == 0) return 0;
    else if (b3 == 1) {
    if (b2 < 0) return (b2 + m);
    else return b2;
  }
  q = a3 / b3;
  t1 = b1;
  t2 = b2;
  t3 = b3;
  b1 = a1 - (q * b1);
  b2 = a2 - (q * b2);
  b3 = a3 - (q * b3);
  a1 = t1;
  a2 = t2;
  a3 = t3;
  goto top;
}
long int findGCD(long int e, long int fn) {
  long int c = e, d = fn;
  long int r;
  while (d != 0) {
    r = c % d;
    c = d;
    d = r;
  }
  return c;
}
int main() 
{
  int choice;
  while (1) {
    printf("\nEnter your choice:\t1.Encrypt\t2.Decrypt\t3.Exit\n");
    scanf("%d", & choice);
    switch (choice) {
    case 1: {
      encrypt();
      break;
    }
    case 2: {
      decrypt();
      break;
    }
    case 3: {
      break;
    }
    default: {
      printf("\nInvalid choice,Enter valid choice.\n");
    }
    }
    if (choice == 3)
      break;
  }
  return 0;
}

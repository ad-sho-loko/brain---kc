# brain---k

brain--kc is a interpreter of brainf**k.
This interpreter is developed in my interest.

# usage

```
$ gcc main.c -o main
$ ./main [source]
```

## Samples

### sample1

```bash
$ cat sample1
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.+++++++.--------.--.

$ ./main sample1
hoge
```

### sample2

```bash
$ cat sample2
++++++++++[>++++++++++<-]>++++.+++++++.--------.--.

$./main sample2
hoge
```

### sample3

```bash
$ cat sample3
+[>,.<]

$./main sample3
echo
echo
hello
hello
```

## License

MIT

## Reference
Sample files in my repository are available to http://www.kmonos.net/alang/etc/brainfuck.php

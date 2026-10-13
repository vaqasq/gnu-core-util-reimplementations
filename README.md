
#### Echo
Reimplements basic functionality as described on its respective man-page, including the -n flag. Your shell will interpret and parse the arguments. This is significant because, as you may have noticed, GNU echo's behavior regarding quotation marks might not be what your expect.

```bash
\$ echo "Hello, World!""Hello"
Hello, World!Hello
```

Therefore, my understanding is that your shell's implementation argument parsing can change how echo will work.

# anew

[tomnomnom/anew](https://github.com/tomnomnom/anew)

```bash
cat things.txt
Zero
One
Two
```

```bash
cat newthings.txt
One
Two
Three
Four
```

```bash
cat newthings.txt | anew -f things.txt
Three
Four
```

## Flags

- To view the output in stdout, but not append to the file, use the dry-run option `-d`.
- To append to the file, but not print anything to stdout, use quiet mode `-q`.

## How to list all the possible compiler languages?

```bash
g++ -v --help |& grep '^\s*\-std=\w'
```

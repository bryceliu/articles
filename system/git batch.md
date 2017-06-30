#### git补丁用法

+ 生成补丁

```bash
# 生成版本R1与R2之间的补丁，每次提交一个patch文件
git format-patch R1..R2
```

+ 应用补丁

```bash
# 应用当前目录下的patch文件
git am *.patch
```

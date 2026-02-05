# 工具安装与环境配置

本章节介绍如果安装d2x工具并创建模板项目, 以及基础的环境配置

## 一、安装d2x工具

### 方法1: 通过xlings包管理器安装 (推荐)

[xlings](https://xlings.d2learn.org)开源包管理器, 可以解决不同环境依赖不一致的问题

<details>
  <summary>点击查看xlings安装命令</summary>

---

#### Linux/MacOS

```bash
curl -fsSL https://d2learn.org/xlings-install.sh | bash
```

#### Windows - PowerShell

```bash
irm https://d2learn.org/xlings-install.ps1.txt | iex
```

> tips: xlings -> [details](https://xlings.d2learn.org)

---

</details>

```
xlings install d2x
```

## 二、书籍和代码检测

进入当前项目的根目录, 运行命令进行测试

**查看文档命令**

运行下面命令后会在浏览器打开新项目的文档/书籍

```
d2x book
```

**代码自动检测功能**

运行下面的checker命令, 可以看到控制台进入实时代码检测模式, 修改文件代码, 控制台会自动更新

```
d2x checker
```
<div align=right>

  🌎 [中文] | [English]
</div>

[中文]: ../setup.html
[English]: ./setup.html

# Tool installation and environment configuration

This chapter introduces how to install the d2x tool, create a template project, and set up the basic environment.

## 1. Install d2x tool

### 1.1 Install via the xlings package manager (recommended)

[xlings](https://xlings.d2learn.org)An open-source package manager that can solve the problem of inconsistent dependencies across different environments

<details>
  <summary>Click to view the installation command for xlings</summary>

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

## 2. Book and Code Inspection

Enter the root directory of the current project and run the command for testing.

**View Document Command**

After running the following command, the documentation/book of the new project will be opened in the browser

```
d2x book
```

**Code auto-detection function**

By running the checker command below, you can see that the console enters real-time code detection mode. As you modify the file code, the console will automatically update

```
d2x checker
```
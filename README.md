# Algorithm Template

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

个人算法竞赛模板库，涵盖常用算法和数据结构的 C++ 实现，主要用于快速查阅和代码复用。同时还包含一个Latex模板，可以自行修改或扩展章节，并重新编译生成属于自己的算法模板。

## 📝 说明
- 本仓库主要用于个人学习与竞赛备赛，代码可能包含多种实现方式（如不同优化版本的背包问题）。

- 部分文件为早期练习代码，风格可能不统一，欢迎提出改进建议。

如果需要对某些部分的描述进行调整（例如更详细的算法列表、特定的使用说明等），随时告诉我。

--- 
## Latex 模板使用说明
### 📁 文件结构

```
Template/
├── main.tex                # 主文件，汇总所有章节并设置文档类
├── template.pdf            # 预编译的 PDF 手册（可直接阅读）
├── chapters/               # 核心章节目录
│ ├── C++ syntax.tex            # C++ 竞赛语法与 STL 速查
│ ├── Combinatorial.tex         # 组合数学（排列组合、容斥、卡特兰数等）
│ ├── Data structure.tex        # 数据结构（并查集、线段树、平衡树等）
│ ├── Dynamic programming.tex   # 动态规划（背包、状压、数位 DP 等）
│ ├── Games.tex                 # 博弈论（Nim、SG 函数、巴什博奕等）
│ ├── Geometry.tex              # 计算几何（凸包、旋转卡壳、半平面交等）
│ ├── Graph.tex                 # 图论（最短路、生成树、强连通、二分图等）
│ ├── Network flow.tex          # 网络流（最大流、费用流、上下界等）
│ ├── Number theory.tex         # 数论（素数筛、扩展欧几里得、CRT 等）
│ └── Other.tex                 # 杂项（对拍、莫队、CDQ 分治等）
├── figures/                # 插图资源（示意图、流程图等）
└── preamble/               # LaTeX 导言区（宏包、样式、自定义命令）
│ ├── packages.tex              # 导入所有必需的宏包
│ ├── settings.tex              # 页面布局、字体、颜色等样式设置
│ └── commands.tex              # 自定义命令（如高亮、算法名标记）
```

### 🚀 如何使用
如果您希望修改章节内容、增删算法或调整样式，可以按以下步骤编译生成新的 PDF：
1. **安装 LaTeX 环境**  
   推荐安装 [TeX Live](https://tug.org/texlive/)（Windows/Mac/Linux）或 [MiKTeX](https://miktex.org/)（Windows）。  
   确保安装 `XeLaTeX` 引擎（通常默认包含）。

2. **安装必要宏包**（如缺失会自动提示）  
   本模板依赖的主要宏包包括：`ctex`、`amsmath`、`amssymb`、`geometry`、`fancyhdr`、`listings`、`minted`（如需代码高亮）、`graphicx`、`hyperref` 等。  
   若使用 TeX Live，可执行 `tlmgr install <package>` 补全。

3. **编译主文件**  
   在 `Template/` 目录下打开终端，执行：
   ```bash
   xelatex main.tex
    ```
    （可能需要连续运行两次以刷新交叉引用和目录）

查看生成的 PDF
编译成功后，会生成 main.pdf，即为您的模板。
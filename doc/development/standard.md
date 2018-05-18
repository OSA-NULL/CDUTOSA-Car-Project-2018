# Project Standard
---

## 代码规范
本项目采用 C 风格进行开发

### 文件
源码均存放在 src 目录下

- 多文件
> - 主文件为 `src.ino` ，其余源文件采用 `.c` 和 `.h` 后缀
> - `.c` 或 `.h` 文件中若使用到 Arduino 标准库中的函数或常量（如 `HIGH` 常量、 `digitalWrite()` 函数等），需要 `#include <Arduino.h>`
> - 文件名：文件名使用小写字母，单词间用下划线隔开，如 *motor_driver.h*

- 头文件
> - define 保护：命名格式为 `__<PATH>_<FILE>_H__` ，如 bar/baz.h 文件：
> ``` c
#ifndef __BAR_BAZ_H__
#define __BAR_BAZ_H__
// 空行
...
// 空行
#endif // __BAR_BAZ_H__
```
> - 头文件中应该用注释对各 API 函数进行说明，格式为：
> ``` c
> /*
>  * int bar(int a, char c);
>  * 功能：
>  *   巴拉巴拉巴拉巴拉巴拉巴拉巴拉巴拉，
>  *   巴拉巴拉巴拉巴拉
>  * 参数：
>  *   a: 第一个参数巴拉巴拉
>  *   c: balabalalalalalalalala
>  * 返回：
>  *   成功返回 1 ，错误返回 0
>  */
> ```
> *此处格式受 MD 语法限制，实际编写时保持所有星号对齐*


- include 规则
> - `.h` 文件中只 include 该文件中用到的头文件，而相应 `.c` 文件需要的头文件直接在 `.c` 文件中 include 。
> - include 顺序（每部分间需有一空行）：
>  1. `.c` 文件对应的头文件
>  2. 系统文件
>  3. 其他库的 .h 文件
>  4. 本项目内 .h 文件

- 内联函数
> 方便起见，简短且逻辑简单的函数均定义为 inline 函数，如果是 api 函数，需在头文件中进行内联函数的定义

### 作用域
总的规则就是保持作用域尽可能小，即尽可能将作用域限制在使用范围

- static 的使用
> - 静态变量
>  1. 函数内的局部静态变量：需要谨慎使用，除非你清楚其用法并确实需要这样使用
>  2. 静态全局变量：不需要在该源文件外访问的全局变量均必须定义为静态的；需要文件外部调用的，应在头文件用 extern 关键字声明
> - 静态函数
>  1. 所有未在相应头文件中声明的函数（即只在当前 `.c` 文件中调用的函数），均必须声明为静态的（除 main 函数外）

### 函数
尽可能将构成特定功能的代码块写成一个函数，函数不宜过长，一般控制在 40 行以下；函数应保证调用方式简单

- 参数顺序：输入参数在前，输出参数在后
- 在不影响实现的情况下，输入参数一般声明为 const 的，输出参数一般声明为指针类型
- 内联函数
- 方便起见，简短且逻辑简单的函数均定义为 inline 函数，如果是 api 函数，需在头文件中进行内联函数的定义
- 非特殊情况尽量不使用 C++ 函数特性

### 命名约定

- 通用规则
> 函数命名, 变量命名, 文件命名要有描述性; 少用缩写，只有常见的已经默许的缩写可以允许使用。
>
> ``` c
> // 允许的变量名：
> int price_count_reader;    // 无缩写
> int num_errors;            // "num" 是一个常见的写法
> int num_dns_connections;   // 人人都知道 "DNS" 是什么
> ```
> ``` c
> // 不规范的变量名：
> int n;                     // 毫无意义.
> int nerr;                  // 含糊不清的缩写.
> int n_comp_conns;          // 含糊不清的缩写.
> int wgc_connections;       // 只有贵团队知道是什么意思.
> int pc_reader;             // "pc" 有太多可能的解释了.
> int cstmr_id;              // 删减了若干字母.
> ```

- 文件命名
> - 文件名要全部小写, 单词间用下划线（_）隔开
> - 项目主文件为 src.ino ，其余 C 源文件以 `.c` 结尾，头文件以 `.h` 结尾
>
> ``` c
> // 允许的文件名：
> my_useful_class.cc
> myusefulclass.cc
> myusefulclass_test.cc // _unittest 和 _regtest 已弃用
> ```

- 类型命名
> - 针对结构体（struct）、联合体（union）、枚举（enum）定义的类型名：类型名称的每个单词首字母均大写, 不包含下划线
> ``` c
> // 结构体
> struct UrlTableProperties {
>      ...
> };
> //
> // 枚举
> enum UrlTableErrors {
>     ...
> };
> //
> // 类型定义
> typedef struct {
>     ...
> } PropertiesMap;
> ```

- 变量命名
> - 一律小写, 单词之间用下划线连接
> ``` c
> char *table_name;  // 好 - 用下划线.
> char *tablename;   // 好 - 全小写.
> //
> char *tableName;  // 差 - 混合大小写
> ```

- 常量命名
> - 声明为 `const` 的变量, 或在程序运行期间其值始终保持不变的, 命名时以 “k” 开头, 大小写混合
> ``` c
> const int kDaysInAWeek = 7;
> ```

- 宏命名
> - 常量尽量用 const 定义，短函数尽量用 inline 函数，尽量不用宏
> - 宏名用全大写加下划线构成
> ``` c
> #define ROUND(x) ...
> #define PI_ROUNDED 3.0
> ```

- 枚举成员常量命名
> - 与常量或宏的命名规则一致
> ``` c
> enum UrlTableErrors {
>     kOK = 0,
>     kErrorOutOfMemory,
>     kErrorMalformedInput,
> };
> //
> enum AlternateUrlTableErrors {
>     OK = 0,
>     OUT_OF_MEMORY = 1,
>     MALFORMED_INPUT = 2,
> };
> ```

- 函数命名
> - 函数名第一个单词开头小写，后续单词首字母大写，不加下划线
> ``` c
> addTableEntry()
> deleteUrl()
> openFileOrDie()
> ```

### 格式
- 行长度限制：80
- TAB 缩进标准：4 位空格符
- 声明、定义指针时星号的位置紧挨变量名：`int *point1, *point2;`
- 灵活地使用空行区分开不同类型的代码块或一个过程，比如一类 include 完成后加一行空行，函数定义前后必须有空行，等
- 大括号位置：
> - 函数：
> ``` c
> void
> fun(int a)
> {
>     ...
> }
> ```
> - 判断、循环（if、switch、which、for）
> ``` c
> if (condition1) {
>     ...
> } else if (condition2) {
>     ...
> } else {
>     ...
> }
> //
> switch (var) {
>     case 0: {    // 缩进 4 空格
>         ...;     // 缩进 8 空格
>         break;
>     }
>     case 1: {
>         ...;
>         break;
>     }
>     default: {
>         assert(false);
>     }           // 大括号不可省略，必须含有 default
> }
> //
> do {
>     ...
> } while(condition);
> // 任何情况都必须有大括号，不可省略
> // 循环体内为空时，需在大括号内显式地写上 continue
> ```
> - 结构体、联合体、枚举
> ``` c
> struct StructName {
>     ...
> } struct_variable;
> ```

- 函数声明、定义、调用格式
> - 多行规则：参数过多时可换行，两种方式换行：一，第一个参数与函数名同行，则换行后的参数行首应与第一个参数对齐；二，第一个参数可直接写在新行，此时第一个参数相对函数名保持两倍缩进，即 8 个空格符，后续换行与第一个参数对齐
> - 函数声明：函数修饰关键词、返回值类型占单独一行
> - 函数定义：同函数声明，同时大括号也应该单独一行
> - 函数调用：参数过多时遵守多行规则
> ``` c
> // 声明，未换行
> static int *
> ReallyLongFunctionName(Type1 par_name1, Type2 par_name2, Type3 par_name3);
> // 定义，换行规则一示例
> static int *
> ReallyLongFunctionName(
>         Type1 par_name1, Type2 par_name2,
>         Type3 par_name3, Type4 par_name4)
> {
>     DoSomething();
>     ...
> }
> // 调用，换行规则二示例
> int *return_value = ReallyLongFunctionName（
>                             Type1 par_name1, Type2 par_name2,
>                             Type3 par_name3);
> // 由于不同字体、Markdown 解析问题，Type1 和 Type3 可能显示效果未对齐
> // 实际写代码时应将其对齐，编辑器注意使用等宽字体
> ```

- 函数返回值
> - 不要在 return 表达式里加上非必须的括号
> ``` c
> return value;    // 简单表达式一定不要加括号
> return (some_long_condition &&
>         (another_condition1 || another_condition2));
> // 表达式较复杂时，可以加括号提高可读性
> ```
> ``` c
> // 错误示范
> return (value);   // 毕竟从来不会写 var = (value);
> return(result);   // return 可不是函数！
> ```
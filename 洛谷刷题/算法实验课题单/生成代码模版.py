import os

# 目标文件夹路径（你的指定路径）
TARGET_DIR = r"D:\学习\Algorithm\洛谷刷题\算法实验课题单"

def generate_code_file():
    # 检查目标文件夹是否存在
    if not os.path.exists(TARGET_DIR):
        print(f"错误：目标文件夹不存在！路径：{TARGET_DIR}")
        input("按回车键退出...")
        return
    
    # 切换到目标文件夹
    os.chdir(TARGET_DIR)
    
    # 获取用户输入的文件名
    filename = input("请输入要生成的文件名（无需后缀，默认生成 .cpp 文件）：").strip()
    
    # 校验文件名
    if not filename:
        print("错误：文件名不能为空！")
        input("按回车键退出...")
        return
    
    # 拼接完整文件名
    fullname = f"{filename}.cpp"
    full_path = os.path.join(TARGET_DIR, fullname)
    
    # 代码模板内容
    code_template = """#include<bits/stdc++.h>
using namespace std;
int main() {
    
    return 0;
}"""
    
    # 写入文件
    try:
        with open(fullname, "w", encoding="utf-8") as f:
            f.write(code_template)
        print(f"成功生成文件：{full_path}")
    except Exception as e:
        print(f"错误：文件生成失败！原因：{str(e)}")
    
    input("按回车键退出...")

if __name__ == "__main__":
    generate_code_file()
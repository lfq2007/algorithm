import os
import subprocess
from datetime import datetime

# 配置：你的本地仓库路径
repo_path = r"D:\学习\Algorithm"

def run_cmd(cmd, cwd=None):
    """运行 shell 命令，强制使用 UTF-8 编码，避免中文乱码或解码错误"""
    try:
        result = subprocess.run(
            cmd,
            cwd=cwd,
            capture_output=True,
            text=True,
            encoding='utf-8',          # 关键：指定 UTF-8
            errors='replace'           # 遇到非法字节就替换，不崩溃
        )
        return result.returncode, result.stdout.strip(), result.stderr.strip()
    except Exception as e:
        return -1, "", str(e)

def main():
    print("🔄 开始自动推送流程...")
    try:
        os.chdir(repo_path)
    except Exception as e:
        print(f"❌ 无法进入目录 {repo_path}: {e}")
        return

    # 检查是否有更改
    code, stdout, stderr = run_cmd(["git", "status", "--porcelain"])
    if code != 0:
        print(f"❌ git status 失败: {stderr}")
        return

    if not stdout:
        print("✅ 仓库已是最新状态，没有需要提交的更改。")
        return

    # git add .
    print("📦 正在添加所有更改 (git add .)...")
    code, _, stderr = run_cmd(["git", "add", "."])
    if code != 0:
        print(f"❌ git add 失败: {stderr}")
        return

    # 生成带时间的提交信息
    now = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    commit_message = f"Update at {now}"

    # git commit
    print(f'📝 正在提交: "{commit_message}"')
    code, _, stderr = run_cmd(["git", "commit", "-m", commit_message])
    if code != 0:
        print(f"❌ git commit 失败: {stderr}")
        return

    # git push
    print("🚀 正在推送至远程仓库 (git push)...")
    code, _, stderr = run_cmd(["git", "push"])
    if code != 0:
        print(f"❌ git push 失败: {stderr}")
        return

    print("✅ 所有更改已成功推送到远程仓库！")

if __name__ == "__main__":
    main()
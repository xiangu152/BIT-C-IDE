import subprocess

def format_cpp_file(file_path):
    try:
        # 使用clang-format工具自动排版C++文件
        subprocess.run(['clang-format', '-i', file_path], check=True)
        print(f"文件 {file_path} 已成功自动排版。")
    except subprocess.CalledProcessError:
        print(f"无法自动排版文件 {file_path}。")
def main():
    path=input()
    print(path)
    format_cpp_file(path)
main()

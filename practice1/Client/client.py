import socket

HOST = "127.0.0.1"
PORT = 5050

def run_client():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        print(f"Connected to KVSS server at {HOST}:{PORT}")
        print("Type commands like: KV/1.0 PUT key value | KV/1.0 GET key | KV/1.0 DEL key | KV/1.0 STATS | KV/1.0 QUIT")

        while True:
            try:
                line = input("> ").strip()
                if not line:
                    continue

                # Gửi request
                s.sendall((line + "\n").encode("utf-8"))

                # Nhận response
                response = s.recv(1024).decode("utf-8").strip()
                print(response)

                # Nếu QUIT thì thoát
                if line.upper().startswith("KV/1.0 QUIT"):
                    break

            except (KeyboardInterrupt, EOFError):
                print("\nExiting client.")
                break

if __name__ == "__main__":
    run_client()
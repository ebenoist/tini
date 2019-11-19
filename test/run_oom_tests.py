from run_outer_tests import Command

def main():
    Command([
        "docker",
        "build",
        "-t",
        "leak",
        "-f",
        "./test/oom/Dockerfile.oom.test",
        "./",
    ], "").run(retcode=0)

    Command([
        "docker",
        "run",
        "--memory",
        "32M",
        "-e",
        "TINI_PREEMPTIVE_MEMORY_LIMITER_THRESHOLD=50",
        "leak"
    ], "").run(retcode=143)

if __name__ == "__main__":
    main()

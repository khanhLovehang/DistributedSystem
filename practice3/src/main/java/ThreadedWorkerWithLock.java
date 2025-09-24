public class ThreadedWorkerWithLock extends Thread {
    private final ResourcesExploiterWithLock rExp;
    public ThreadedWorkerWithLock(ResourcesExploiterWithLock resource) {
        this.rExp = resource;
    }
    @Override
    public void run() {
        super.run();

        for (int i = 0; i < 1000; i++){
            rExp.exploit();
        }
    }
}

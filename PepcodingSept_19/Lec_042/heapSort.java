import java.util.ArrayList;

public class heapSort {
    public static class heap {
        private ArrayList<Integer> arr;
        private boolean isMax = false;

        public heap() {
            this.arr = new ArrayList<Integer>();
        }

        public void createHeap(int[] ar) {
            this.arr = new ArrayList<Integer>();
            for (int ele : ar) {
                this.arr.add(ele);
            }
            int n = arr.size() - 1;
            for (int i = arr.size() - 1; i >= 0; i--) {
                downheapify(i, n);
            }
        }

        public heap(int[] ar, boolean Max_) {
            this.isMax = Max_;
            createHeap(ar);
        }

        public heap(int[] ar) {
            createHeap(ar);
        }

        public void display() {
            for (int ele : this.arr) {
                System.out.println(ele);
            }
        }

        public int size() {
            return this.arr.size();
        }

        public void push(int data) {
            this.arr.add(data);
            upheapify(arr.size() - 1);
        }

        public void pop() {
            swap(0, arr.size() - 1);
            arr.remove(arr.size() - 1);
            downheapify(0, this.arr.size() - 1);
        }

        public int top() {
            return arr.get(0);
        }

        public void update(int idx, int data) {
            arr.set(idx, data);
            upheapify(idx);
            downheapify(idx, this.arr.size() - 1);
        }

        public void upheapify(int child) {
            int par = (child - 1) / 2;
            if (par >= 0 && compareTo(child, par) > 0) {
                swap(par, child);
                upheapify(par);
            }
        }

        public void downheapify(int idx, int lidx) {
            int maxidx = idx;
            int lchild = 2 * idx + 1;
            int rchild = 2 * idx + 2;

            if (lchild <= lidx && compareTo(lchild, maxidx) > 0) {
                maxidx = lchild;
            }
            if (rchild <= lidx && compareTo(rchild, maxidx) > 0) {
                maxidx = rchild;
            }
            if (maxidx != idx) {
                swap(idx, maxidx);
                downheapify(maxidx, lidx);
            }
        }

        public void swap(int i, int j) {
            int val1 = arr.get(i);
            int val2 = arr.get(j);

            arr.set(i, val2);
            arr.set(j, val1);
        }

        // public boolean compareTo(int i,int j)
        // {
        // if(this.isMax)
        // {
        // if(arr.get(i)<arr.get(j))
        // {
        // return true;
        // }
        // else
        // {
        // return false;
        // }
        // }
        // else
        // {
        // if(arr.get(i)>arr.get(j))
        // {
        // return true;
        // }
        // else
        // {
        // return false;
        // }
        // }
        // }
        public int compareTo(int child, int par) {
            if (isMax) {
                return (arr.get(child) - arr.get(par));
            } else {
                return (arr.get(par) - arr.get(child));
            }
        }

    }

    public static void main(String[] args) {
        int[] arr = { 10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13 };
        heap obj = new heap(arr, false);
        int n = arr.length - 1;
        for (int i = 0; i <= n; i++) {
            obj.swap(0, n - i);
            obj.downheapify(0, n - i - 1);
        }
        obj.display();

    }
}
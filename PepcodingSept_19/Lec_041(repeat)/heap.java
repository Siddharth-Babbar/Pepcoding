import java.util.ArrayList;

public class heap {
    private ArrayList<Integer> arr;

    public heap() {
        this.arr = new ArrayList<Integer>();
    }

    public heap(int[] ar) {
        this.arr = new ArrayList<Integer>();
        for (int ele : ar) {
            this.arr.add(ele);
        }
        for (int i = arr.size() - 1; i >= 0; i--) {
            downheapify(i);
        }
    }
    public void display()
    {
        for(int ele:this.arr)
         {
             System.out.println(ele);
         }
    }
    public void push(int data) {
        this.arr.add(data);
        upheapify(arr.size() - 1);
    }

    public void pop() {
        swap(0, arr.size() - 1);
        arr.remove(arr.size() - 1);
        downheapify(0);
    }

    public int top() {
        return arr.get(0);
    }

    public void update(int idx, int data) {
        arr.set(idx, data);
        upheapify(idx);
        downheapify(idx);
    }

    public void upheapify(int child) {
        int par = (child - 1) / 2;
        if (par >= 0 && arr.get(par) < arr.get(child)) {
            swap(par, child);
            upheapify(par);
        }
    }

    public void downheapify(int idx) {
        int maxidx = idx;
        int lchild = 2 * idx + 1;
        int rchild = 2 * idx + 2;

        if (lchild < arr.size() && arr.get(maxidx) < arr.get(lchild)) {
            maxidx = lchild;
        }
        if (rchild < arr.size() && arr.get(maxidx) < arr.get(rchild)) {
            maxidx = rchild;
        }
        if (maxidx != idx) {
            swap(idx, maxidx);
            downheapify(maxidx);
        }
    }

    public void swap(int i, int j) {
        int val1 = arr.get(i);
        int val2 = arr.get(j);

        arr.set(i, val2);
        arr.set(j, val1);
    }
}
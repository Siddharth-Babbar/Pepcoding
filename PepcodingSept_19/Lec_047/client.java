public class client {
    public static void main(String[] args) {
        // HashMap_<Integer,Integer> map=new HashMap_<>();
        // map.put(33,100);
        // map.put(43,134);
        // map.put(53,100);
        // map.put(63,134);
        // map.put(73,100);
        // map.put(5,134);
        // map.put(4,100);
        // map.put(3,134);
        // map.put(2,100);
        // map.put(1,134);
        // map.put(100,1);
        HashMap_<String, Integer> map = new HashMap_<>();
        map.put("asd",1);
        map.put("zxc",1);
        map.put("qwe",1);
        map.put("rty",1);

        System.out.println(map.keySet());
        System.out.println(map.getOrDefault("103", 0));
        // System.out.println(map.get(22));
        // System.out.println(map.remove(2));
        // System.out.println(map.containsKey(2));
        System.out.println(map);

    }

}
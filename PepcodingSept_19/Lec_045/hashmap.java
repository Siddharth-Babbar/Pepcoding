import java.util.HashMap;
import java.util.ArrayList;

public class hashmap
{
    public static void main(String[] args)
    {
        // HashMapCreation01();
        // HashMapCreation02("aszxfjrjbsbhcbebnmebbceuh");
        // HashMapCreation03("ansjdhjhjhushudhshcush");
        // int[] arr={1,14,2,13,4,8,9,10,11,12,5,6};
        // System.out.println(largestSeries(arr));
        // int[] arr1={1,1,1,2,2,3,5};
        // int[] arr2={1,1,2,2,2,3,3,5,4};
        // int[] ans=Common(arr1,arr2);
        // for(int ele:ans)
        //  {
        //      System.out.println(ele);
        //  }
        int[] arr1={1,1,1,2,2,3,5};
        int[] arr2={1,1,2,2,2,3,3,5,4};
        // int[] ans=intersect(arr1,arr2);
        int[] ans=intersection(arr1,arr2);
        for(int ele:ans)
         {
             System.out.println(ele);
         }

    }
    public static void HashMapCreation01()
    {
        HashMap<String,Integer> map=new HashMap<>();
        map.put("India",100);
        map.put("China",80);
        map.put("USA",1000);
        map.put("NEPAL",200);
        map.put("Bangladesh",500);
        map.put("India",3000);

        // System.out.println(map);
        for(String s:map.keySet())
         {
             System.out.println(s+map.get(s));
         }

    }
    public static void HashMapCreation02(String str)
    {
        HashMap<Character,Integer> map=new HashMap<>();
        for(int i=0;i<str.length();i++)
        {
            char ch=str.charAt(i);
            // if(!map.containsKey(ch))
            //  {
                //  map.put(ch,1);
            //     map.putIfAbsent(ch,1);
            //  }
            // map.put(ch,map.get(ch)+1);
            map.put(ch,map.getOrDefault(ch,0)+1);
        
        }

        // for(Character ch:map.keySet())
        //  {
        //      System.out.println(ch+":->"+map.get(ch));
        //  }
        System.out.println(map);
    }
    public static void HashMapCreation03(String str)
    {
        HashMap<Character,ArrayList<Integer>> map=new HashMap<>();
        for(int i=0;i<str.length();i++)
         {
             char ch=str.charAt(i);
             if(!map.containsKey(ch))
              {
                 map.put(ch,new ArrayList<>());
              }
             map.get(ch).add(i);
         }
        
         System.out.println(map);
    }

    public static int largestSeries(int[] arr)
    {
        HashMap<Integer,Boolean> map=new HashMap<>();
        
        int size=-1;
        int num=-1;
    
        for(int ele:arr)
         {
             map.put(ele,true);
         }
        
        for(Integer ele:map.keySet())
         {
             if(map.get(ele))
              {
                  if(map.containsKey(ele-1))
                   {
                       map.put(ele,false);
                   }
    
              }
         }
    
        for(Integer key:map.keySet())
         {
             if(map.get(key))
              {
                  int number=key+1;
                  int smallSize=1;
    
                  while(map.containsKey(number))
                   {
                       smallSize++;
                       number++;
                   }
                   if(smallSize>size)
                    {
                        size=smallSize;
                        num=number;
                    }
              }
         }
        return size;
    }
    public static int[] Common(int[] nums1,int[] nums2)
    {
        HashMap<Integer,Boolean> map=new HashMap<>();
        for(int ele:nums1)
         {
             map.put(ele,true);
         }
        ArrayList<Integer> myans=new ArrayList<>();
        for(int ele:nums2)
         {
             for(int key:map.keySet())
              {
                  if(map.containsKey(ele))
                   {
                       if(map.get(ele))
                        {
                            myans.add(ele);
                            map.put(ele,false);
                        }
                   }

                }
         }
        int[] ans=new int[myans.size()];
        int i=0;
        for(int ele:myans)
         {
             ans[i]=ele;
             i++;
         }
        return ans;
    }
    public static int[] intersection(int[] nums1, int[] nums2)
    {
        HashMap<Integer,Boolean> map=new HashMap<>();

        for(int ele:nums1)
         {
             map.put(ele,true);
         }
        ArrayList<Integer> myans=new ArrayList<>();
        for(int ele:nums2)
         {
             if(map.containsKey(ele))
              {
                  myans.add(ele);
                  map.remove(ele);
              }
         }
        int[] ans=new int[myans.size()];
        int i=0;
        for(int ele:myans)
         {
             ans[i]=ele;
             i++;
         }
        return ans;
    }
    public static int[] intersect(int[] nums1, int[] nums2)
    {
        HashMap<Integer,Integer> map=new HashMap<>();

        for(int ele: nums1)
         {
             map.put(ele,map.getOrDefault(ele,0)+1);
         }
        ArrayList<Integer> myans=new ArrayList<>();
        for(int ele:nums2)
         {
             if(map.containsKey(ele))
              {    
                  myans.add(ele);
                  if(map.get(ele)==1)
                   {
                       map.remove(ele);
                   }
                  else
                   {
                       map.put(ele,map.get(ele)-1);
                   }
              }
         }
        int[] ans=new int[myans.size()];
        int i=0;
        for(int ele:myans)
         {
             ans[i]=ele;
             i++;
         }
        return ans;

    }
}
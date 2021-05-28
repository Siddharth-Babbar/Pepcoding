public class client
{
    public static void main(String[] args)
    {
        String s=args[0];
        HuffmanED hed=new HuffmanED("asdgvajdvmnasvcamnsvcasdaskmndbckasjbdcmanbscmsanbcmsnbcmsnbcmsnbcdmdsncmsbcmsnbcskgymnszdcvmzcvn");
        String encode=hed.Encoder(s);
        String decode=hed.Decoder(encode);
        System.out.println(encode+":->"+decode);
        
    }
}
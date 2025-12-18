#!/bin/bash
DIRSEARCH="docker run -it --rm dirsearch:v0.4.3 "
DOMAIN=$1
TODAY=$(date)
DIRECTORY=${DOMAIN}_recon
echo "Creating Directory $DIRECTORY."
mkdir $DIRECTORY



nmap_scan()
{
    nmap $DOMAIN > $DIRECTORY/nmap
    echo "The results of nmap scan are stored in $DIRECTORY/nmap."

}
dirsearch_scan()
{
    $DIRSEARCH -u $DOMAIN -e php -o $DIRECTORY/dirsearch
    echo "The results of dirsearch scan are stored in $DIRECTORY/dirsearch."
}
crt_scan()
{

     curl "https://crt.sh/?q=$DOMAIN&output=json" -o $DIRECTORY/crt
     echo "The results of crt scan are stored in $DIRECTORY/crt."
}
case $2 in 
  nmap-only)
    nmap_scan
    ;;
  dirsearch-only)
    dirsearch_scan
    ;;
  crt-only)
    crt_scan
    ;;
  *)
    nmap_scan
    dir_scan
    crt_scan
    ;;
esac
echo "Generating recon report from output files..."
TODAY=$(date)
echo "This scan was created on $TODAY" > $DIRECTORY/report
echo "Results for nmap:" >> $DIRECTORY/report
grep -E "^s*\S+\s+\S+\s+\S+\s*$" $DIRECTORY/nmap >> $DIRECTORY/report
echo "Results for Dirsearch:" >> $DIRECTORY/report
cat $DIRECTORY/dirsearch >> $DIRECTORY/report
echo "Results for crt.sh:" >> $DIRECTORY/report
jq -r ".[] | .name_value" $DIRECTORY/crt >> $DIRECTORY/report
    


<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="pl" xml:lang="pl">
<head>
<title>Zadanie zaliczeniowe CPP - algorytm Brandesa</title>
<!-- 2016-12-26 Mon 21:06 -->
<meta  http-equiv="Content-Type" content="text/html;charset=utf-8" />
<meta  name="generator" content="Org-mode" />
<meta  name="author" content="Krzysztof Rządca" />
<style type="text/css">
 <!--/*--><![CDATA[/*><!--*/
  .title  { text-align: center; }
  .todo   { font-family: monospace; color: red; }
  .done   { color: green; }
  .tag    { background-color: #eee; font-family: monospace;
            padding: 2px; font-size: 80%; font-weight: normal; }
  .timestamp { color: #bebebe; }
  .timestamp-kwd { color: #5f9ea0; }
  .right  { margin-left: auto; margin-right: 0px;  text-align: right; }
  .left   { margin-left: 0px;  margin-right: auto; text-align: left; }
  .center { margin-left: auto; margin-right: auto; text-align: center; }
  .underline { text-decoration: underline; }
  #postamble p, #preamble p { font-size: 90%; margin: .2em; }
  p.verse { margin-left: 3%; }
  pre {
    border: 1px solid #ccc;
    box-shadow: 3px 3px 3px #eee;
    padding: 8pt;
    font-family: monospace;
    overflow: auto;
    margin: 1.2em;
  }
  pre.src {
    position: relative;
    overflow: visible;
    padding-top: 1.2em;
  }
  pre.src:before {
    display: none;
    position: absolute;
    background-color: white;
    top: -10px;
    right: 10px;
    padding: 3px;
    border: 1px solid black;
  }
  pre.src:hover:before { display: inline;}
  pre.src-sh:before    { content: 'sh'; }
  pre.src-bash:before  { content: 'sh'; }
  pre.src-emacs-lisp:before { content: 'Emacs Lisp'; }
  pre.src-R:before     { content: 'R'; }
  pre.src-perl:before  { content: 'Perl'; }
  pre.src-java:before  { content: 'Java'; }
  pre.src-sql:before   { content: 'SQL'; }

  table { border-collapse:collapse; }
  caption.t-above { caption-side: top; }
  caption.t-bottom { caption-side: bottom; }
  td, th { vertical-align:top;  }
  th.right  { text-align: center;  }
  th.left   { text-align: center;   }
  th.center { text-align: center; }
  td.right  { text-align: right;  }
  td.left   { text-align: left;   }
  td.center { text-align: center; }
  dt { font-weight: bold; }
  .footpara:nth-child(2) { display: inline; }
  .footpara { display: block; }
  .footdef  { margin-bottom: 1em; }
  .figure { padding: 1em; }
  .figure p { text-align: center; }
  .inlinetask {
    padding: 10px;
    border: 2px solid gray;
    margin: 10px;
    background: #ffffcc;
  }
  #org-div-home-and-up
   { text-align: right; font-size: 70%; white-space: nowrap; }
  textarea { overflow-x: auto; }
  .linenr { font-size: smaller }
  .code-highlighted { background-color: #ffff00; }
  .org-info-js_info-navigation { border-style: none; }
  #org-info-js_console-label
    { font-size: 10px; font-weight: bold; white-space: nowrap; }
  .org-info-js_search-highlight
    { background-color: #ffff00; color: #000000; font-weight: bold; }
  /*]]>*/-->
</style>
<link href="cpp-theme.css" rel="stylesheet">
<script type="text/javascript">
/*
@licstart  The following is the entire license notice for the
JavaScript code in this tag.

Copyright (C) 2012-2013 Free Software Foundation, Inc.

The JavaScript code in this tag is free software: you can
redistribute it and/or modify it under the terms of the GNU
General Public License (GNU GPL) as published by the Free Software
Foundation, either version 3 of the License, or (at your option)
any later version.  The code is distributed WITHOUT ANY WARRANTY;
without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  See the GNU GPL for more details.

As additional permission under GNU GPL version 3 section 7, you
may distribute non-source (e.g., minimized or compacted) forms of
that code without the copy of the GNU GPL normally required by
section 4, provided you include this license notice and a URL
through which recipients can access the Corresponding Source.


@licend  The above is the entire license notice
for the JavaScript code in this tag.
*/
<!--/*--><![CDATA[/*><!--*/
 function CodeHighlightOn(elem, id)
 {
   var target = document.getElementById(id);
   if(null != target) {
     elem.cacheClassElem = elem.className;
     elem.cacheClassTarget = target.className;
     target.className = "code-highlighted";
     elem.className   = "code-highlighted";
   }
 }
 function CodeHighlightOff(elem, id)
 {
   var target = document.getElementById(id);
   if(elem.cacheClassElem)
     elem.className = elem.cacheClassElem;
   if(elem.cacheClassTarget)
     target.className = elem.cacheClassTarget;
 }
/*]]>*///-->
</script>
<script type="text/javascript" src="http://orgmode.org/mathjax/MathJax.js"></script>
<script type="text/javascript">
<!--/*--><![CDATA[/*><!--*/
    MathJax.Hub.Config({
        // Only one of the two following lines, depending on user settings
        // First allows browser-native MathML display, second forces HTML/CSS
        //  config: ["MMLorHTML.js"], jax: ["input/TeX"],
            jax: ["input/TeX", "output/HTML-CSS"],
        extensions: ["tex2jax.js","TeX/AMSmath.js","TeX/AMSsymbols.js",
                     "TeX/noUndefined.js"],
        tex2jax: {
            inlineMath: [ ["\\(","\\)"] ],
            displayMath: [ ['$$','$$'], ["\\[","\\]"], ["\\begin{displaymath}","\\end{displaymath}"] ],
            skipTags: ["script","noscript","style","textarea","pre","code"],
            ignoreClass: "tex2jax_ignore",
            processEscapes: false,
            processEnvironments: true,
            preview: "TeX"
        },
        showProcessingMessages: true,
        displayAlign: "center",
        displayIndent: "2em",

        "HTML-CSS": {
             scale: 100,
             availableFonts: ["STIX","TeX"],
             preferredFont: "TeX",
             webFont: "TeX",
             imageFont: "TeX",
             showMathMenu: true,
        },
        MMLorHTML: {
             prefer: {
                 MSIE:    "MML",
                 Firefox: "MML",
                 Opera:   "HTML",
                 other:   "HTML"
             }
        }
    });
/*]]>*///-->
</script>
</head>
<body>
<div id="content">
<h1 class="title">Zadanie zaliczeniowe CPP - algorytm Brandesa</h1>
<div id="table-of-contents">
<h2>Spis tre&#x015b;ci</h2>
<div id="text-table-of-contents">
<ul>
<li><a href="#sec-1">1. Wprowadzenie</a></li>
<li><a href="#sec-2">2. Algorytm Brandesa</a></li>
<li><a href="#sec-3">3. Wejście i wyjście</a></li>
<li><a href="#sec-4">4. Forma oddania zadania</a></li>
<li><a href="#sec-5">5. Kryteria oceny</a></li>
<li><a href="#sec-6">6. Dodatkowe materiały</a></li>
<li><a href="#sec-7">7. FAQ</a></li>
</ul>
</div>
</div>
<p>
Termin zadania: 9 stycznia 2017
</p>

<p>
Modyfikacje treści: 
</p>
<ul class="org-ul">
<li>2016/12/26 FAQ
</li>
<li>2016/12/23 FAQ
</li>
<li>2016/12/13 FAQ
</li>
<li>2016/12/09 ogłoszenie zadania
</li>
</ul>


<div id="outline-container-sec-1" class="outline-2">
<h2 id="sec-1"><span class="section-number-2">1</span> Wprowadzenie</h2>
<div class="outline-text-2" id="text-1">
<p>
Analiza sieci polega m.in. na identyfikacji <span class="underline">ważnych</span>
wierzchołków. Naiwnym sposobem wyrażania ważności wierzchołka jest
np. zliczenie sąsiadów&#x2014;im więcej sąsiadów tym ważniejszy jest
wierzchołek dla sieci. Liczenie sąsiadów nie identyfikuje jednak
ważnych z punktu widzenia spójności sieci wierzchołków-pośredników
(np. wierzchołka łączącego dwie grupy niepołączonych ze sobą
wierzchołków). Zaproponowano wiele alternatywnych miar,
m.in. closeness centrality czy eigenvector centrality; tematem zadania
jest obliczenie pośrednictwa (betweenness).
</p>

<p>
Pośrednictwo węzła \(v\) określa jaka część najkrótszych ścieżek w sieci
przechodzi przez ten węzeł: \(BC(v) = \sum_{s \neq v \neq t}
\frac{\sigma_{st}(v)}{\sigma_{st}}\), gdzie \(\sigma_{st}\) jest liczbą
najkrótszych ścieżek między węzłami \(s\) i \(t\); a \(\sigma_{st}(v)\) jest
liczbą najkrótszych ścieżek między węzłami \(s\) i \(t\) przechodzącymi
przez \(v\).
</p>

<p>
W sieciach opisanych grafami ważonymi obliczenie pośrednictwa wymaga
obliczenia najkrótszych ścieżek między wszystkimi parami węzłów
(np. algorytmem Floyda-Warshalla), z kosztem \(O(|V|^3)\). Na szczęście,
wiele ciekawych sieci nie jest ważonych&#x2014;do takich sieci można
stosować algorytm Brandesa (\(O(|V||E|)\)).
</p>

<p>
Prosimy o zaimplementowanie algorytmu Brandesa w C++ 14.
</p>
</div>
</div>

<div id="outline-container-sec-2" class="outline-2">
<h2 id="sec-2"><span class="section-number-2">2</span> Algorytm Brandesa</h2>
<div class="outline-text-2" id="text-2">
<p>
Pseudokod współbieżnego algorytmu Brandesa przedstawiamy poniżej; dalsze wyjaśnienia w artykułach z bibliografii. Algorytm używa następujących zmiennych:
<code>BC</code>: pośrednictwo; <code>V</code>: wierzchołki; <code>d[w]</code> odległość do wierzchołka w; <code>sigma[w]</code> liczba najkrótszych ścieżek do wierzchołka w; <code>P[w]</code> poprzednicy wierzchołka <code>w</code> na wszystkich najkrótszych ścieżkach; <code>delta[v]</code> wartość pośrednictwa dla <code>v</code> w ścieżkach startujących z <code>s</code>.
</p>

<div class="org-src-container">

<pre class="src src-c"><span class="org-keyword">for</span> each v : V <br>
&nbsp;&nbsp; BC[v] = 0;<br>
<span class="org-keyword">for</span> each s : V { <span class="org-comment-delimiter">// </span><span class="org-comment">in parallel</span><br>
&nbsp;&nbsp; S = stack();<br>
&nbsp;&nbsp; <span class="org-keyword">for</span> all w in V {<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;P[w] = list();<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;sigma[w] = 0;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;d[w] = -1;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;delta[v] = 0;<br>
&nbsp;&nbsp; }<br>
&nbsp;&nbsp; sigma[s] = 1;<br>
&nbsp;&nbsp; d[s] = 0;<br>
&nbsp;&nbsp; Q = queue(); <span class="org-comment-delimiter">// </span><span class="org-comment">FIFO</span><br>
&nbsp;&nbsp; Q.push_back(s);<br>
&nbsp;&nbsp; <span class="org-keyword">while</span> (<span class="org-negation-char">!</span>Q.empty()) {<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;v = Q.pop_front();<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;S.push(v);<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="org-keyword">for</span> each neighbor w of v {<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <span class="org-keyword">if</span> d[w] &lt; 0 {<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Q.push_back(w);<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;d[w] = d[v] + 1;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; }<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <span class="org-keyword">if</span> (d[w] == d[v] + 1) {<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;sigma[w] += sigma[v];<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;P[w].append(v);<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; }<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}<br>
&nbsp;&nbsp; }<br>
&nbsp;&nbsp; <span class="org-keyword">while</span> (<span class="org-negation-char">!</span>S.empty()) {<br>
&nbsp;&nbsp;&nbsp;&nbsp; w = S.pop();<br>
&nbsp;&nbsp;&nbsp;&nbsp; <span class="org-keyword">for</span> each v in P[w]<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;delta[v] += (sigma[v] / sigma[w])(1 + delta[w]);<br>
&nbsp;&nbsp;&nbsp;&nbsp; <span class="org-keyword">if</span> (w != s)<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;BC[w] += delta[w];<br>
&nbsp;&nbsp; }<br>
}<br>
</p>
</pre>
</div>
</div>
</div>


<div id="outline-container-sec-3" class="outline-2">
<h2 id="sec-3"><span class="section-number-2">3</span> Wejście i wyjście</h2>
<div class="outline-text-2" id="text-3">
<p>
Programy będą testowane automatycznie. Prosimy o ścisłe przestrzeganie
podanych poniżej: formatowania nazw plików oraz wejścia i wyjścia
programów.
</p>
</div>

<div id="outline-container-sec-3-1" class="outline-3">
<h3 id="sec-3-1"><span class="section-number-3">3.1</span> Sposób uruchomienia programu</h3>
<div class="outline-text-3" id="text-3-1">
<p>
<code>unzip xx123456; cd xx123456; mkdir build; cd build; cmake ..; make</code>
</p>

<p>
<code>./brandes liczba-wątków plik-wejsciowy plik-wyjsciowy</code>
</p>
</div>
</div>

<div id="outline-container-sec-3-2" class="outline-3">
<h3 id="sec-3-2"><span class="section-number-3">3.2</span> Wejście</h3>
<div class="outline-text-3" id="text-3-2">
<p>
Plik wejściowy opisuje krawędzie w grafie w formacie <code>&lt;wierzchołek1&gt; &lt;wierzchołek2&gt;</code>. Graf jest skierowany. Krawędzie są posortowane po
pierwszym wierzchołku i po drugim wierzchołku. Wierzchołki nie muszą
być numerowane sekwencyjnie (tzn. poprawny jest graf bez
np. wierzchołka o numerze 0). Graf nie musi być spójny. 
</p>

<p>
Program powinien przeprowadzać obliczenia używając <code>liczba-wątków</code>
wątków. W testach wydajnościowych będzie zdecydowanie więcej
wierzchołków niż wątków, ale musisz zapewnić poprawne działanie
programu dla <code>liczba-wątków &lt; 100</code> niezależnie od liczby wierzchołków.
</p>


<p>
Przykładowe wejście:
</p>
<pre class="example">
0 2
2 0
2 3
2 4
3 2
3 5
3 6
</pre>
</div>
</div>

<div id="outline-container-sec-3-3" class="outline-3">
<h3 id="sec-3-3"><span class="section-number-3">3.3</span> Wyjście</h3>
<div class="outline-text-3" id="text-3-3">
<p>
Plik wyjściowy składa się z dokładnie tylu linii, ile jest
wierzchołków z co najmniej jedną krawędzią wychodzącą. \(i\)-ta linia
zawiera dwie liczby: liczbę całkowitą &#x2014; identyfikator
wierzchołka, oraz liczbę rzeczywistą &#x2014; pośrednictwo tego
wierzchołka. Wyjście musi być posortowane po pierwszej kolumnie.
</p>

<p>
Standardowe wyjście programu będzie ignorowane.
</p>

<p>
Plik wyjściowy odpowiadający przykładowemu plikowi wejściowemu:
</p>

<pre class="example">
0 0
2 6
3 4
</pre>
</div>
</div>
</div>


<div id="outline-container-sec-4" class="outline-2">
<h2 id="sec-4"><span class="section-number-2">4</span> Forma oddania zadania</h2>
<div class="outline-text-2" id="text-4">
<p>
Prosimy o oddanie pojedynczego pliku <code>.zip</code> zawierającego pojedynczy katalog odpowiadający loginowi (<code>ab123456</code>), a w nim następujące pliki:
</p>
<ul class="org-ul">
<li>kod źródłowy;
</li>
<li>CMakeLists.txt;
</li>
<li>raport w pliku raport.pdf
</li>
</ul>

<p>
W raporcie opisz twoją implementację i zastosowane optymalizacje. Dla
grafu <code>wiki-vote-sort.txt</code> zmierz speed-up, czyli zmierz czas
działania twojego programu \(p_m\) dla \(m=1, 2, ..., 8\) wątków, a
następnie oblicz przyspieszenie: \(S_m=p_1 / p_m\).
</p>

<p>
CMakeLists powinien kompilować program do jak najszybszej wersji:
pamiętaj o włączeniu optymalizacji kompilatora i wyłączeniu debugowania.
</p>
</div>
</div>

<div id="outline-container-sec-5" class="outline-2">
<h2 id="sec-5"><span class="section-number-2">5</span> Kryteria oceny</h2>
<div class="outline-text-2" id="text-5">
<p>
Będziemy oceniać poprawność, wydajność oraz raport. 
</p>

<p>
Poprawność będziemy oceniać porównując wyniki implementacji z naszym
rozwiązaniem wzorcowym; nasze testy biorą pod uwagę błędy
zaokrągleń. Udostępniamy dwa przykładowe testy, ale nie wyczerpują one
wszystkich przypadków brzegowych &#x2014; pamiętaj o dodaniu własnych
testów. Nie będziemy oceniać wydajności programów niepoprawnych.
</p>

<p>
Szybkość działania będziemy oceniać porównując czas działania waszych
implementacji na sieciach "społecznych", tzn. nie
Erdős'a–Rényi'ego. Pojedyncze wykonanie programu będziemy ograniczać
do kilku (max. 5) minut.
</p>
</div>
</div>


<div id="outline-container-sec-6" class="outline-2">
<h2 id="sec-6"><span class="section-number-2">6</span> Dodatkowe materiały</h2>
<div class="outline-text-2" id="text-6">
<p>
Prosimy o niekorzystanie z kodów źródłowych - gotowych implementacji
algorytmu Brandesa. Zalecamy natomiast przeczytanie następujących prac:
</p>

<ul class="org-ul">
<li>A faster algorithm for betweenness centrality, U Brandes, Journal of
Mathematical Sociology, 2001 Taylor &amp; Francis, <a href="https://kops.uni-konstanz.de/bitstream/handle/123456789/5739/algorithm.pdf?sequence=1">https://kops.uni-konstanz.de/bitstream/handle/123456789/5739/algorithm.pdf?sequence=1</a>
</li>
<li>Parallel algorithms for evaluating centrality indices in real-world
networks DA Bader, K Madduri, <a href="https://smartech.gatech.edu/bitstream/handle/1853/14428/GT-CSE-06-13.pdf">https://smartech.gatech.edu/bitstream/handle/1853/14428/GT-CSE-06-13.pdf</a>
</li>
<li>Dane do testów wydajnościowych można wziąć z <a href="http://snap.stanford.edu/data/">http://snap.stanford.edu/data/</a>.
</li>
</ul>
</div>
</div>


<div id="outline-container-sec-7" class="outline-2">
<h2 id="sec-7"><span class="section-number-2">7</span> FAQ</h2>
<div class="outline-text-2" id="text-7">
<ul class="org-ul">
<li>Dokładność obliczeń
</li>
</ul>

<p>
Proszę używać liczb zmiennoprzecinkowych o podwójnej precyzji.
</p>

<ul class="org-ul">
<li>Czy możemy założyc, że wejście jest poprawne?
</li>
</ul>

<p>
Tak. Czyli program może zachowywać się nieprzewidywalnie dla wejść
niespełniających specyfikacji.
</p>

<ul class="org-ul">
<li>Czy możemy stworzyć dodatkowe, pomocnicze wątki?
</li>
</ul>

<p>
Liczba wątków "liczących", tzn. wykonujących algorytm Bradesa, musi
być równa <code>liczba-watkow</code>, pierwszemu parametrowi wywołania programu. Można stworzyć
dodatkowe, pomocnicze wątki, ale co najwyżej O(<code>liczba-watkow</code>). Dodatkowe wątki
mogą wykonać co najwyżej O(1) operacji.
</p>

<ul class="org-ul">
<li>Czy można korzystać z dodatkowych bibliotek?
</li>
</ul>

<p>
Nie. W rozwiązaniu można korzystać tylko ze standardowej biblioteki
CPP14. W szczególności nie można korzystać z Boosta.
</p>

<ul class="org-ul">
<li>Co można założyć o identyfikatorach węzłów grafu?
</li>
</ul>

<p>
Zmieszczą się do zwykłego <code>int</code>.
</p>
</div>
</div>
</div>
<div id="postamble" class="status">
<p class="date">Data: 2016/12/26</p>
<p class="author">Autor: Krzysztof Rządca</p>
<p class="date">Created: 2016-12-26 Mon 21:06</p>
<p class="creator"><a href="http://www.gnu.org/software/emacs/">Emacs</a> 25.1.1 (<a href="http://orgmode.org">Org</a> mode 8.2.10)</p>
<p class="validation"><a href="http://validator.w3.org/check?uri=referer">Validate</a></p>
</div>
</body>
</html>

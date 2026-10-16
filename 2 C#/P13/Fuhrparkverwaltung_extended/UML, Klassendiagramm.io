<?xml version="1.0" encoding="UTF-8"?>
<mxfile host="app.diagrams.net" modified="2025-01-30T12:00:00.000Z" agent="5.0" etag="abc123" version="24.0.0">
  <diagram name="Klassendiagramm" id="klassendiagramm">
    <mxGraphModel dx="1422" dy="794" grid="1" gridSize="10" guides="1" tooltips="1" connect="1" arrows="1" fold="1" page="1" pageScale="1" pageWidth="827" pageHeight="1169" math="0" shadow="0">
      <root>
        <mxCell id="0" />
        <mxCell id="1" parent="0" />
        
        <!-- Auto Klasse -->
        <object label="Auto" id="auto">
          <mxCell style="swimlane;fontStyle=1;align=center;verticalAlign=top;childLayout=stackLayout;horizontal=1;startSize=26;horizontalStack=0;resizeParent=1;resizeParentMax=0;resizeLast=0;collapsible=1;marginBottom=0;" vertex="1" parent="1">
            <mxGeometry x="40" y="40" width="280" height="340" as="geometry" />
          </mxCell>
        </object>
        <mxCell id="auto-fields" value="- hersteller: string" style="text;strokeColor=none;fillColor=none;align=left;verticalAlign=top;spacingLeft=4;spacingRight=4;overflow=hidden;rotatable=0;points=[[0,0.5],[1,0.5]];portConstraint=eastwest;" vertex="1" parent="auto">
          <mxGeometry y="26" width="280" height="26" as="geometry" />
        </mxCell>
        <mxCell id="auto-line1" value="" style="line;strokeWidth=1;fillColor=none;align=left;verticalAlign=middle;spacingTop=-1;spacingLeft=3;spacingRight=3;rotatable=0;labelPosition=right;points=[];portConstraint=eastwest;strokeColor=inherit;" vertex="1" parent="auto">
          <mxGeometry y="52" width="280" height="8" as="geometry" />
        </mxCell>
        <mxCell id="auto-props" value="+ Hersteller: string {get; set;}&#xa;+ Baujahr: int {get; set;}&#xa;+ Alter: int {get;}" style="text;strokeColor=none;fillColor=none;align=left;verticalAlign=top;spacingLeft=4;spacingRight=4;overflow=hidden;rotatable=0;points=[[0,0.5],[1,0.5]];portConstraint=eastwest;" vertex="1" parent="auto">
          <mxGeometry y="60" width="280" height="78" as="geometry" />
        </mxCell>
        <mxCell id="auto-line2" value="" style="line;strokeWidth=1;fillColor=none;align=left;verticalAlign=middle;spacingTop=-1;spacingLeft=3;spacingRight=3;rotatable=0;labelPosition=right;points=[];portConstraint=eastwest;strokeColor=inherit;" vertex="1" parent="auto">
          <mxGeometry y="138" width="280" height="8" as="geometry" />
        </mxCell>
        <mxCell id="auto-methods" value="+ Auto()&#xa;+ Auto(hersteller:string, baujahr:int)&#xa;+ ToString(): string&#xa;+ Equals(obj:object): bool&#xa;+ GetHashCode(): int" style="text;strokeColor=none;fillColor=none;align=left;verticalAlign=top;spacingLeft=4;spacingRight=4;overflow=hidden;rotatable=0;points=[[0,0.5],[1,0.5]];portConstraint=eastwest;" vertex="1" parent="auto">
          <mxGeometry y="146" width="280" height="130" as="geometry" />
        </mxCell>

        <!-- IIterator Interface -->
        <object label="&lt;&lt;interface&gt;&gt;&#xa;IIterator&lt;T&gt;" id="iiterator">
          <mxCell style="swimlane;fontStyle=3;align=center;verticalAlign=top;childLayout=stackLayout;horizontal=1;startSize=40;horizontalStack=0;resizeParent=1;resizeParentMax=0;resizeLast=0;collapsible=1;marginBottom=0;" vertex="1" parent="1">
            <mxGeometry x="400" y="40" width="200" height="120" as="geometry" />
          </mxCell>
        </object>
        <mxCell id="iiterator-line" value="" style="line;strokeWidth=1;fillColor=none;align=left;verticalAlign=middle;spacingTop=-1;spacingLeft=3;spacingRight=3;rotatable=0;labelPosition=right;points=[];portConstraint=eastwest;strokeColor=inherit;" vertex="1" parent="iiterator">
          <mxGeometry y="40" width="200" height="8" as="geometry" />
        </mxCell>
        <mxCell id="iiterator-methods" value="+ HasNext(): bool&#xa;+ Next(): T" style="text;strokeColor=none;fillColor=none;align=left;verticalAlign=top;spacingLeft=4;spacingRight=4;overflow=hidden;rotatable=0;points=[[0,0.5],[1,0.5]];portConstraint=eastwest;fontStyle=2;" vertex="1" parent="iiterator">
          <mxGeometry y="48" width="200" height="52" as="geometry" />
        </mxCell>

        <!-- LinkedList Klasse -->
        <object label="LinkedList&lt;T&gt;" id="linkedlist">
          <mxCell style="swimlane;fontStyle=1;align=center;verticalAlign=top;childLayout=stackLayout;horizontal=1;startSize=26;horizontalStack=0;resizeParent=1;resizeParentMax=0;resizeLast=0;collapsible=1;marginBottom=0;" vertex="1" parent="1">
            <mxGeometry x="40" y="440" width="280" height="280" as="geometry" />
          </mxCell>
        </object>
        <mxCell id="linkedlist-fields" value="- head: ListNode&#xa;- count: int" style="text;strokeColor=none;fillColor=none;align=left;verticalAlign=top;spacingLeft=4;spacingRight=4;overflow=hidden;rotatable=0;points=[[0,0.5],[1,0.5]];portConstraint=eastwest;" vertex="1" parent="linkedlist">
          <mxGeometry y="26" width="280" height="52" as="geometry" />
        </mxCell>
        <mxCell id="linkedlist-line1" value="" style="line;strokeWidth=1;fillColor=none;align=left;verticalAlign=middle;spacingTop=-1;spacingLeft=3;spacingRight=3;rotatable=0;labelPosition=right;points=[];portConstraint=eastwest;strokeColor=inherit;" vertex="1" parent="linkedlist">
          <mxGeometry y="78" width="280" height="8" as="geometry" />
        </mxCell>
        <mxCell id="linkedlist-props" value="+ Count: int {get;}&#xa;+ this[index:int]: T {get; set;}" style="text;strokeColor=none;fillColor=none;align=left;verticalAlign=top;spacingLeft=4;spacingRight=4;overflow=hidden;rotatable=0;points=[[0,0.5],[1,0.5]];portConstraint=eastwest;" vertex="1" parent="linkedlist">
          <mxGeometry y="86" width="280" height="52" as="geometry" />
        </mxCell>
        <mxCell id="linkedlist-line2" value="" style="line;strokeWidth=1;fillColor=none;align=left;verticalAlign=middle;spacingTop=-1;spacingLeft=3;spacingRight=3;rotatable=0;labelPosition=right;points=[];portConstraint=eastwest;strokeColor=inherit;" vertex="1" parent="linkedlist">
          <mxGeometry y="138" width="280" height="8" as="geometry" />
        </mxCell>
        <mxCell id="linkedlist-methods" value="+ LinkedList()&#xa;+ Add(item:T): void&#xa;+ Remove(index:int): bool&#xa;+ GetIterator(): IIterator&lt;T&gt;&#xa;+ PrintAll(): void" style="text;strokeColor=none;fillColor=none;align=left;verticalAlign=top;spacingLeft=4;spacingRight=4;overflow=hidden;rotatable=0;points=[[0,0.5],[1,0.5]];portConstraint=eastwest;" vertex="1" parent="linkedlist">
          <mxGeometry y="146" width="280" height="130" as="geometry" />
        </mxCell>

        <!-- Fuhrpark Klasse -->
        <object label="Fuhrpark" id="fuhrpark">
          <mxCell style="swimlane;fontStyle=1;align=center;verticalAlign=top;childLayout=stackLayout;horizontal=1;startSize=26;horizontalStack=0;resizeParent=1;resizeParentMax=0;resizeLast=0;collapsible=1;marginBottom=0;" vertex="1" parent="1">
            <mxGeometry x="400" y="440" width="320" height="300" as="geometry" />
          </mxCell>
        </object>
        <mxCell id="fuhrpark-fields" value="- fahrzeuge: LinkedList&lt;Auto&gt;" style="text;strokeColor=none;fillColor=none;align=left;verticalAlign=top;spacingLeft=4;spacingRight=4;overflow=hidden;rotatable=0;points=[[0,0.5],[1,0.5]];portConstraint=eastwest;" vertex="1" parent="fuhrpark">
          <mxGeometry y="26" width="320" height="26" as="geometry" />
        </mxCell>
        <mxCell id="fuhrpark-line1" value="" style="line;strokeWidth=1;fillColor=none;align=left;verticalAlign=middle;spacingTop=-1;spacingLeft=3;spacingRight=3;rotatable=0;labelPosition=right;points=[];portConstraint=eastwest;strokeColor=inherit;" vertex="1" parent="fuhrpark">
          <mxGeometry y="52" width="320" height="8" as="geometry" />
        </mxCell>
        <mxCell id="fuhrpark-props" value="+ AnzahlFahrzeuge: int {get;}" style="text;strokeColor=none;fillColor=none;align=left;verticalAlign=top;spacingLeft=4;spacingRight=4;overflow=hidden;rotatable=0;points=[[0,0.5],[1,0.5]];portConstraint=eastwest;" vertex="1" parent="fuhrpark">
          <mxGeometry y="60" width="320" height="26" as="geometry" />
        </mxCell>
        <mxCell id="fuhrpark-events" value="+ AutoHinzugefuegt:AutoHinzugefuegtEventHandler" style="text;strokeColor=none;fillColor=none;align=left;verticalAlign=top;spacingLeft=4;spacingRight=4;overflow=hidden;rotatable=0;points=[[0,0.5],[1,0.5]];portConstraint=eastwest;" vertex="1" parent="fuhrpark">
          <mxGeometry y="86" width="320" height="26" as="geometry" />
        </mxCell>
        <mxCell id="fuhrpark-line2" value="" style="line;strokeWidth=1;fillColor=none;align=left;verticalAlign=middle;spacingTop=-1;spacingLeft=3;spacingRight=3;rotatable=0;labelPosition=right;points=[];portConstraint=eastwest;strokeColor=inherit;" vertex="1" parent="fuhrpark">
          <mxGeometry y="112" width="320" height="8" as="geometry" />
        </mxCell>
        <mxCell id="fuhrpark-methods" value="+ Fuhrpark()&#xa;+ Aufnehmen(auto:Auto): void&#xa;+ Inventur(): void&#xa;+ BerechneDurchschnittFlottenalter(): double&#xa;+ EntferneFahrzeug(index:int): bool&#xa;- OnAutoHinzugefuegt(e:AutoHinzugefuegtEventArgs): void" style="text;strokeColor=none;fillColor=none;align=left;verticalAlign=top;spacingLeft=4;spacingRight=4;overflow=hidden;rotatable=0;points=[[0,0.5],[1,0.5]];portConstraint=eastwest;" vertex="1" parent="fuhrpark">
          <mxGeometry y="120" width="320" height="156" as="geometry" />
        </mxCell>

        <!-- AutoHinzugefuegtEventArgs Klasse -->
        <object label="AutoHinzugefuegtEventArgs" id="eventargs">
          <mxCell style="swimlane;fontStyle=1;align=center;verticalAlign=top;childLayout=stackLayout;horizontal=1;startSize=26;horizontalStack=0;resizeParent=1;resizeParentMax=0;resizeLast=0;collapsible=1;marginBottom=0;" vertex="1" parent="1">
            <mxGeometry x="780" y="440" width="240" height="120" as="geometry" />
          </mxCell>
        </object>
        <mxCell id="eventargs-props" value="+ HinzugefuegtesAuto: Auto {get;}" style="text;strokeColor=none;fillColor=none;align=left;verticalAlign=top;spacingLeft=4;spacingRight=4;overflow=hidden;rotatable=0;points=[[0,0.5],[1,0.5]];portConstraint=eastwest;" vertex="1" parent="eventargs">
          <mxGeometry y="26" width="240" height="26" as="geometry" />
        </mxCell>
        <mxCell id="eventargs-line" value="" style="line;strokeWidth=1;fillColor=none;align=left;verticalAlign=middle;spacingTop=-1;spacingLeft=3;spacingRight=3;rotatable=0;labelPosition=right;points=[];portConstraint=eastwest;strokeColor=inherit;" vertex="1" parent="eventargs">
          <mxGeometry y="52" width="240" height="8" as="geometry" />
        </mxCell>
        <mxCell id="eventargs-methods" value="+ AutoHinzugefuegtEventArgs(auto:Auto)" style="text;strokeColor=none;fillColor=none;align=left;verticalAlign=top;spacingLeft=4;spacingRight=4;overflow=hidden;rotatable=0;points=[[0,0.5],[1,0.5]];portConstraint=eastwest;" vertex="1" parent="eventargs">
          <mxGeometry y="60" width="240" height="26" as="geometry" />
        </mxCell>

        <!-- Info Klasse -->
        <object label="Info" id="info">
          <mxCell style="swimlane;fontStyle=1;align=center;verticalAlign=top;childLayout=stackLayout;horizontal=1;startSize=26;horizontalStack=0;resizeParent=1;resizeParentMax=0;resizeLast=0;collapsible=1;marginBottom=0;" vertex="1" parent="1">
            <mxGeometry x="780" y="600" width="300" height="80" as="geometry" />
          </mxCell>
        </object>
        <mxCell id="info-line" value="" style="line;strokeWidth=1;fillColor=none;align=left;verticalAlign=middle;spacingTop=-1;spacingLeft=3;spacingRight=3;rotatable=0;labelPosition=right;points=[];portConstraint=eastwest;strokeColor=inherit;" vertex="1" parent="info">
          <mxGeometry y="26" width="300" height="8" as="geometry" />
        </mxCell>
        <mxCell id="info-methods" value="+ AutoAufgenommenHandler(sender:object, e:AutoHinzugefuegtEventArgs): void" style="text;strokeColor=none;fillColor=none;align=left;verticalAlign=top;spacingLeft=4;spacingRight=4;overflow=hidden;rotatable=0;points=[[0,0.5],[1,0.5]];portConstraint=eastwest;" vertex="1" parent="info">
          <mxGeometry y="34" width="300" height="40" as="geometry" />
        </mxCell>

        <!-- Rational Klasse -->
        <object label="Rational" id="rational">
          <mxCell style="swimlane;fontStyle=1;align=center;verticalAlign=top;childLayout=stackLayout;horizontal=1;startSize=26;horizontalStack=0;resizeParent=1;resizeParentMax=0;resizeLast=0;collapsible=1;marginBottom=0;" vertex="1" parent="1">
            <mxGeometry x="40" y="780" width="280" height="180" as="geometry" />
          </mxCell>
        </object>
        <mxCell id="rational-props" value="+ Zaehler: int {get;}&#xa;+ Nenner: int {get;}" style="text;strokeColor=none;fillColor=none;align=left;verticalAlign=top;spacingLeft=4;spacingRight=4;overflow=hidden;rotatable=0;points=[[0,0.5],[1,0.5]];portConstraint=eastwest;" vertex="1" parent="rational">
          <mxGeometry y="26" width="280" height="52" as="geometry" />
        </mxCell>
        <mxCell id="rational-line" value="" style="line;strokeWidth=1;fillColor=none;align=left;verticalAlign=middle;spacingTop=-1;spacingLeft=3;spacingRight=3;rotatable=0;labelPosition=right;points=[];portConstraint=eastwest;strokeColor=inherit;" vertex="1" parent="rational">
          <mxGeometry y="78" width="280" height="8" as="geometry" />
        </mxCell>
        <mxCell id="rational-methods" value="+ Rational(zaehler:int, nenner:int)&#xa;+ operator *(a:Rational, b:Rational): Rational&#xa;+ ToString(): string" style="text;strokeColor=none;fillColor=none;align=left;verticalAlign=top;spacingLeft=4;spacingRight=4;overflow=hidden;rotatable=0;points=[[0,0.5],[1,0.5]];portConstraint=eastwest;" vertex="1" parent="rational">
          <mxGeometry y="86" width="280" height="78" as="geometry" />
        </mxCell>

        <!-- Beziehungen -->
        <!-- Fuhrpark -> LinkedList (Komposition) -->
        <mxCell id="rel1" style="endArrow=diamondThin;endFill=1;endSize=24;html=1;rounded=0;" edge="1" parent="1" source="fuhrpark" target="linkedlist">
          <mxGeometry width="160" relative="1" as="geometry">
            <mxPoint x="360" y="580" as="sourcePoint" />
            <mxPoint x="520" y="580" as="targetPoint" />
          </mxGeometry>
        </mxCell>

        <!-- LinkedList -> IIterator (Implementierung) -->
        <mxCell id="rel2" style="endArrow=block;dashed=1;endFill=0;endSize=12;html=1;rounded=0;" edge="1" parent="1" source="linkedlist" target="iiterator">
          <mxGeometry width="160" relative="1" as="geometry">
            <mxPoint x="200" y="300" as="sourcePoint" />
            <mxPoint x="360" y="300" as="targetPoint" />
            <Array as="points">
              <mxPoint x="180" y="300" />
              <mxPoint x="500" y="300" />
            </Array>
          </mxGeometry>
        </mxCell>

        <!-- Fuhrpark -> Auto (Assoziation) -->
        <mxCell id="rel3" style="endArrow=open;endFill=1;endSize=12;html=1;rounded=0;" edge="1" parent="1" source="fuhrpark" target="auto">
          <mxGeometry width="160" relative="1" as="geometry">
            <mxPoint x="400" y="400" as="sourcePoint" />
            <mxPoint x="320" y="400" as="targetPoint" />
            <Array as="points">
              <mxPoint x="360" y="400" />
            </Array>
          </mxGeometry>
        </mxCell>

        <!-- Fuhrpark -> AutoHinzugefuegtEventArgs (Abhängigkeit) -->
        <mxCell id="rel4" style="endArrow=open;endFill=0;dashed=1;html=1;rounded=0;" edge="1" parent="1" source="fuhrpark" target="eventargs">
          <mxGeometry width="160" relative="1" as="geometry">
            <mxPoint x="720" y="520" as="sourcePoint" />
            <mxPoint x="780" y="520" as="targetPoint" />
          </mxGeometry>
        </mxCell>

        <!-- Info -> AutoHinzugefuegtEventArgs (Abhängigkeit) -->
        <mxCell id="rel5" style="endArrow=open;endFill=0;dashed=1;html=1;rounded=0;" edge="1" parent="1" source="info" target="eventargs">
          <mxGeometry width="160" relative="1" as="geometry">
            <mxPoint x="900" y="580" as="sourcePoint" />
            <mxPoint x="900" y="560" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
      </root>
    </mxGraphModel>
  </diagram>
</mxfile>
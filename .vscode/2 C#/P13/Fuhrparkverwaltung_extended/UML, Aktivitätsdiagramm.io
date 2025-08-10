<?xml version="1.0" encoding="UTF-8"?>
<mxfile host="app.diagrams.net" modified="2025-01-30T12:00:00.000Z" agent="5.0" etag="abc123" version="24.0.0">
  <diagram name="Aktivitaetsdiagramm" id="aktivitaetsdiagramm">
    <mxGraphModel dx="1422" dy="794" grid="1" gridSize="10" guides="1" tooltips="1" connect="1" arrows="1" fold="1" page="1" pageScale="1" pageWidth="827" pageHeight="1600" math="0" shadow="0">
      <root>
        <mxCell id="0" />
        <mxCell id="1" parent="0" />
        
        <!-- Titel -->
        <mxCell id="title" value="Aktivitätsdiagramm: Auto zum Fuhrpark hinzufügen" style="text;html=1;strokeColor=none;fillColor=none;align=center;verticalAlign=middle;whiteSpace=wrap;rounded=0;fontSize=16;fontStyle=1;" vertex="1" parent="1">
          <mxGeometry x="264" y="10" width="300" height="30" as="geometry" />
        </mxCell>
        
        <!-- Start -->
        <mxCell id="start" value="" style="ellipse;whiteSpace=wrap;html=1;aspect=fixed;fillColor=#000000;" vertex="1" parent="1">
          <mxGeometry x="399" y="60" width="30" height="30" as="geometry" />
        </mxCell>
        
        <!-- Fuhrpark erstellen -->
        <mxCell id="activity1" value="Fuhrpark erstellen" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#dae8fc;strokeColor=#6c8ebf;" vertex="1" parent="1">
          <mxGeometry x="344" y="120" width="140" height="60" as="geometry" />
        </mxCell>
        
        <mxCell id="arrow1" style="endArrow=block;html=1;rounded=0;" edge="1" parent="1" source="start" target="activity1">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="414" y="90" as="sourcePoint" />
            <mxPoint x="414" y="120" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
        <!-- Info-Objekt erstellen -->
        <mxCell id="activity2" value="Info-Objekt erstellen" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#d5e8d4;strokeColor=#82b366;" vertex="1" parent="1">
          <mxGeometry x="344" y="210" width="140" height="60" as="geometry" />
        </mxCell>
        
        <mxCell id="arrow2" style="endArrow=block;html=1;rounded=0;" edge="1" parent="1" source="activity1" target="activity2">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="414" y="180" as="sourcePoint" />
            <mxPoint x="414" y="210" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
        <!-- Event Handler registrieren -->
        <mxCell id="activity3" value="Event Handler&#xa;registrieren" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#fff2cc;strokeColor=#d6b656;" vertex="1" parent="1">
          <mxGeometry x="344" y="300" width="140" height="60" as="geometry" />
        </mxCell>
        
        <mxCell id="arrow3" style="endArrow=block;html=1;rounded=0;" edge="1" parent="1" source="activity2" target="activity3">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="414" y="270" as="sourcePoint" />
            <mxPoint x="414" y="300" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
        <!-- Auto erstellen -->
        <mxCell id="activity4" value="Auto erstellen" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#f8cecc;strokeColor=#b85450;" vertex="1" parent="1">
          <mxGeometry x="344" y="390" width="140" height="60" as="geometry" />
        </mxCell>
        
        <mxCell id="arrow4" style="endArrow=block;html=1;rounded=0;" edge="1" parent="1" source="activity3" target="activity4">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="414" y="360" as="sourcePoint" />
            <mxPoint x="414" y="390" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
        <!-- Entscheidung: Auto gültig? -->
        <mxCell id="decision1" value="Auto != null?" style="rhombus;whiteSpace=wrap;html=1;fillColor=#ffe6cc;strokeColor=#d79b00;" vertex="1" parent="1">
          <mxGeometry x="364" y="480" width="100" height="80" as="geometry" />
        </mxCell>
        
        <mxCell id="arrow5" style="endArrow=block;html=1;rounded=0;" edge="1" parent="1" source="activity4" target="decision1">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="414" y="450" as="sourcePoint" />
            <mxPoint x="414" y="480" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
        <!-- Auto zur Liste hinzufügen -->
        <mxCell id="activity5" value="Auto zur LinkedList&#xa;hinzufügen" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#e1d5e7;strokeColor=#9673a6;" vertex="1" parent="1">
          <mxGeometry x="344" y="590" width="140" height="60" as="geometry" />
        </mxCell>
        
        <!-- Ja-Pfad -->
        <mxCell id="arrow6" value="ja" style="endArrow=block;html=1;rounded=0;" edge="1" parent="1" source="decision1" target="activity5">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="414" y="560" as="sourcePoint" />
            <mxPoint x="414" y="590" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
        <!-- Fehlerbehandlung -->
        <mxCell id="activity_error" value="Fehlermeldung ausgeben" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#ffcccc;strokeColor=#ff0000;" vertex="1" parent="1">
          <mxGeometry x="564" y="490" width="140" height="60" as="geometry" />
        </mxCell>
        
        <!-- Nein-Pfad -->
        <mxCell id="arrow_error" value="nein" style="endArrow=block;html=1;rounded=0;" edge="1" parent="1" source="decision1" target="activity_error">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="464" y="520" as="sourcePoint" />
            <mxPoint x="564" y="520" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
        <!-- Console Ausgabe -->
        <mxCell id="activity6" value="Console Ausgabe:&#xa;&quot;Auto aufgenommen&quot;" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#cce5ff;strokeColor=#0066cc;" vertex="1" parent="1">
          <mxGeometry x="344" y="680" width="140" height="60" as="geometry" />
        </mxCell>
        
        <mxCell id="arrow7" style="endArrow=block;html=1;rounded=0;" edge="1" parent="1" source="activity5" target="activity6">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="414" y="650" as="sourcePoint" />
            <mxPoint x="414" y="680" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
        <!-- EventArgs erstellen -->
        <mxCell id="activity7" value="AutoHinzugefuegtEventArgs&#xa;erstellen" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#ffccff;strokeColor=#cc00cc;" vertex="1" parent="1">
          <mxGeometry x="344" y="770" width="140" height="60" as="geometry" />
        </mxCell>
        
        <mxCell id="arrow8" style="endArrow=block;html=1;rounded=0;" edge="1" parent="1" source="activity6" target="activity7">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="414" y="740" as="sourcePoint" />
            <mxPoint x="414" y="770" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
        <!-- Event auslösen -->
        <mxCell id="activity8" value="Event auslösen:&#xa;OnAutoHinzugefuegt()" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#ccffcc;strokeColor=#00cc00;" vertex="1" parent="1">
          <mxGeometry x="344" y="860" width="140" height="60" as="geometry" />
        </mxCell>
        
        <mxCell id="arrow9" style="endArrow=block;html=1;rounded=0;" edge="1" parent="1" source="activity7" target="activity8">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="414" y="830" as="sourcePoint" />
            <mxPoint x="414" y="860" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
        <!-- Entscheidung: Event Handler registriert? -->
        <mxCell id="decision2" value="Event Handler&#xa;registriert?" style="rhombus;whiteSpace=wrap;html=1;fillColor=#ffe6cc;strokeColor=#d79b00;" vertex="1" parent="1">
          <mxGeometry x="354" y="950" width="120" height="80" as="geometry" />
        </mxCell>
        
        <mxCell id="arrow10" style="endArrow=block;html=1;rounded=0;" edge="1" parent="1" source="activity8" target="decision2">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="414" y="920" as="sourcePoint" />
            <mxPoint x="414" y="950" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
        <!-- Info Handler aufrufen -->
        <mxCell id="activity9" value="Info.AutoAufgenommenHandler()&#xa;aufrufen" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#d5e8d4;strokeColor=#82b366;" vertex="1" parent="1">
          <mxGeometry x="344" y="1060" width="140" height="60" as="geometry" />
        </mxCell>
        
        <!-- Ja-Pfad für Event Handler -->
        <mxCell id="arrow11" value="ja" style="endArrow=block;html=1;rounded=0;" edge="1" parent="1" source="decision2" target="activity9">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="414" y="1030" as="sourcePoint" />
            <mxPoint x="414" y="1060" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
        <!-- Info Console Ausgabe -->
        <mxCell id="activity10" value="Info: Console Ausgabe&#xa;Auto-Details" style="rounded=1;whiteSpace=wrap;html=1;fillColor=#d5e8d4;strokeColor=#82b366;" vertex="1" parent="1">
          <mxGeometry x="344" y="1150" width="140" height="60" as="geometry" />
        </mxCell>
        
        <mxCell id="arrow12" style="endArrow=block;html=1;rounded=0;" edge="1" parent="1" source="activity9" target="activity10">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="414" y="1120" as="sourcePoint" />
            <mxPoint x="414" y="1150" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
        <!-- Merge -->
        <mxCell id="merge1" value="" style="ellipse;whiteSpace=wrap;html=1;aspect=fixed;fillColor=#ffcc99;strokeColor=#d79b00;" vertex="1" parent="1">
          <mxGeometry x="399" y="1240" width="30" height="30" as="geometry" />
        </mxCell>
        
        <mxCell id="arrow13" style="endArrow=block;html=1;rounded=0;" edge="1" parent="1" source="activity10" target="merge1">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="414" y="1210" as="sourcePoint" />
            <mxPoint x="414" y="1240" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
        <!-- Nein-Pfad für Event Handler -->
        <mxCell id="arrow_no_handler" value="nein" style="endArrow=block;html=1;rounded=0;" edge="1" parent="1" source="decision2" target="merge1">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="474" y="990" as="sourcePoint" />
            <mxPoint x="550" y="1255" as="targetPoint" />
            <Array as="points">
              <mxPoint x="550" y="990" />
              <mxPoint x="550" y="1255" />
            </Array>
          </mxGeometry>
        </mxCell>
        
        <!-- Fehler-Merge -->
        <mxCell id="arrow_error_merge" style="endArrow=block;html=1;rounded=0;" edge="1" parent="1" source="activity_error" target="merge1">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="634" y="550" as="sourcePoint" />
            <mxPoint x="634" y="1255" as="targetPoint" />
            <Array as="points">
              <mxPoint x="634" y="1255" />
            </Array>
          </mxGeometry>
        </mxCell>
        
        <!-- Ende -->
        <mxCell id="end" value="" style="ellipse;whiteSpace=wrap;html=1;aspect=fixed;fillColor=#000000;" vertex="1" parent="1">
          <mxGeometry x="399" y="1300" width="30" height="30" as="geometry" />
        </mxCell>
        
        <mxCell id="arrow_end" style="endArrow=block;html=1;rounded=0;" edge="1" parent="1" source="merge1" target="end">
          <mxGeometry width="50" height="50" relative="1" as="geometry">
            <mxPoint x="414" y="1270" as="sourcePoint" />
            <mxPoint x="414" y="1300" as="targetPoint" />
          </mxGeometry>
        </mxCell>
        
        <!-- Swimlanes -->
        <mxCell id="swimlane1" value="Main" style="swimlane;html=1;startSize=20;horizontal=0;fillColor=#fff2cc;strokeColor=#d6b656;" vertex="1" parent="1">
          <mxGeometry x="40" y="60" width="100" height="400" as="geometry" />
        </mxCell>
        
        <mxCell id="swimlane2" value="Fuhrpark" style="swimlane;html=1;startSize=20;horizontal=0;fillColor=#dae8fc;strokeColor=#6c8ebf;" vertex="1" parent="1">
          <mxGeometry x="40" y="460" width="100" height="600" as="geometry" />
        </mxCell>
        
        <mxCell id="swimlane3" value="Info" style="swimlane;html=1;startSize=20;horizontal=0;fillColor=#d5e8d4;strokeColor=#82b366;" vertex="1" parent="1">
          <mxGeometry x="40" y="1060" width="100" height="200" as="geometry" />
        </mxCell>
      </root>
    </mxGraphModel>
  </diagram>
</mxfile>